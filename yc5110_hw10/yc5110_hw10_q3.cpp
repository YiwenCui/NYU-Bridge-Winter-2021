#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main1();
int main2();
int *createArray(int &arrSize);
void printLineNumOfTarget1(int *arr, int arrSize, int target);
void printLineNumOfTarget2(vector<int> vec, int target);
vector<int> createVector();

int main()
{
    main1();
    cout<<endl;
    main2();
    return 0;
}

int *createArray(int &arrSize)
{
    int numArrSize = 0;
    int expandedCapacity = 1;
    int *numArr = new int[1];
    int userInput;

    while (userInput != -1)
    {
        cin >> userInput;
        if (numArrSize == expandedCapacity)
        {
            int *currArray = new int[2 * expandedCapacity];
            for (int i = 0; i < numArrSize; i++)
            {
                currArray[i] = numArr[i];
            }
            delete[] numArr;
            numArr = currArray;
            expandedCapacity *= 2;
        }

        numArr[numArrSize] = userInput;
        numArrSize++;
    }

    arrSize = numArrSize;

    return numArr;
}

void printLineNumOfTarget1(int *arr, int arrSize, int target)
{
    cout << target << " shows in lines ";
    int count;
    for (int i = 0; i < arrSize - 1; i++)
    {
        if (arr[i] == target)
        {
            count++;
        }
    }
    int *newArray = new int[count];
    int start = 0;
    for (int i = 0; i < arrSize - 1; i++)
    {
        if (arr[i] == target)
        {
            newArray[start] = i + 1;
            start++;
        }
    }
    for (int i = 0; i < count; i++)
    {
        if (i != count - 1)
        {
            cout << newArray[i] << ", ";
        }
        else
        {
            cout << newArray[i];
        }
    }
    delete[] newArray;
}

vector<int> createVector()
{
    vector<int> numsVec;
    int userInput;
    while (userInput != -1)
    {
        cin >> userInput;
        numsVec.push_back(userInput);
    }
    return numsVec;
}

void printLineNumOfTarget2(vector<int> vec, int target)
{
    vector<int> newVec;
    cout << target << " shows in lines ";
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] == target)
            newVec.push_back(i + 1);
    }

    for (int i = 0; i < newVec.size(); i++)
    {
        if (i != newVec.size() - 1)
        {
            cout << newVec[i] << ", ";
        }
        else
        {
            cout << newVec[i];
        }
    }
}

int main1()
{
    int *ptr = nullptr;
    int arrSize = 0;
    int userInput;

    cout << "Please enter a sequence of positive integers, each in a separate line. End your input by typing -1." << endl;
    ptr = createArray(arrSize);
    cout << "Please enther a number you want to search." << endl;
    cin >> userInput;

    printLineNumOfTarget1(ptr, arrSize, userInput);

    return 0;
}

int main2()
{
    int userInput;
    vector<int> vector1;
    cout << "Please enter a sequence of positive integers, each in a separate line. End your input by typing -1." << endl;
    vector1 = createVector();
    cout << "Please enther a number you want to search." << endl;
    cin >> userInput;

    printLineNumOfTarget2(vector1,userInput);

    return 0;
}