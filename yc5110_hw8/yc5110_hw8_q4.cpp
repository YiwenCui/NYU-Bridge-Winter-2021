#include <iostream>
#include <string>
using namespace std;

const int MY_PIN[5] = {0, 5, 1, 9, 6};
bool firstExecution(int num[], int userInput[]);

int main()
{
    // first execution
    int pin[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num1[10] = {3, 2, 3, 1, 1, 3, 2, 2, 1, 3};
    int num2[10] = {1, 1, 2, 3, 1, 2, 2, 3, 3, 3};
    int idx;
    int arrSize = 10;
    int userInput[5];
    //first execution
    cout << "Please enter your PIN according to the following mapping:" << endl;
    cout << "PIN:" << '\t';

    for (idx = 0; idx < arrSize; idx++)
    {
        cout << pin[idx] << " ";
    }
    cout << endl;

    cout << "NUM:" << '\t';
    for (idx = 0; idx < arrSize; idx++)
    {
        cout << num1[idx] << " ";
    }
    cout << endl;

    string userInputStr1 = "";
    cin >> userInputStr1;
    for (int i = 0; i < userInputStr1.length(); i++)
    {
        userInput[i] = (int)userInputStr1[i] - '0';
    }

    if (firstExecution(num1, userInput) == 0)
    {
        cout << "Your PIN is not correct" << endl;
    }
    else
    {
        cout << "Your PIN is correct" << endl;
    }
    //second execution
    cout << "Please enter your PIN according to the following mapping:" << endl;
    cout << "PIN:" << '\t';

    for (idx = 0; idx < arrSize; idx++)
    {
        cout << pin[idx] << " ";
    }
    cout << endl;

    cout << "NUM:" << '\t';
    for (idx = 0; idx < arrSize; idx++)
    {
        cout << num2[idx] << " ";
    }
    cout << endl;

    string userInputStr2 = "";
    cin >> userInputStr2;
    for (int i = 0; i < userInputStr1.length(); i++)
    {
        userInput[i] = (int)userInputStr2[i] - '0';
    }

    if (firstExecution(num2, userInput) == 0)
    {
        cout << "Your PIN is not correct" << endl;
    }
    else
    {
        cout << "Your PIN is correct" << endl;
    }

    return 0;
}

bool firstExecution(int num[], int userInput[])
{
    int i, j;

    //array MY_PIN size is 5
    int arrSize = 5;
    bool passwordIsCorrect = true;
    for (i = 0; i < arrSize; i++)
    {
        if (userInput[i] != num[MY_PIN[i]])
        {
            passwordIsCorrect = false;
            break;
        }
    }

    return passwordIsCorrect;
}