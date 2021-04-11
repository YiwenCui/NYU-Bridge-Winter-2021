#include <iostream>
#include <string>
using namespace std;

int minInArray(int arr[], int arrSize);
int findMinNum(int arr[], int arrSize);
void findMinNumIndices(int arr[], int arrSize);

const int NUM_OF_INT = 20;
int main()
{
    int currentNum;
    int idx;
    int inputArray[NUM_OF_INT];
    cout << "Please enter 20 integers separated by a space:" << endl;
    for (idx = 0; idx < NUM_OF_INT; idx++)
    {
        cin >> currentNum;
        inputArray[idx] = currentNum;
    }
    findMinNumIndices(inputArray, NUM_OF_INT);

    return 0;
}
int findMinNum(int arr[], int arrSize)
{
    int idx;
    int min = arr[0];
    for (idx = 1; idx < arrSize; idx++)
    {
        if (arr[idx] < min)
        {
            min = arr[idx];
        }
    }
    return min;
}

void findMinNumIndices(int arr[], int arrSize)
{
    int idx;
    for (idx = 0; idx < arrSize; idx++)
    {
        if (arr[idx] == findMinNum(arr, arrSize))
        {
            cout << idx << " ";
        }
    }
}