#include <iostream>
#include <string>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int &arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main()
{
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}
void reverseArray(int arr[], int arrSize)
{
    int idx;
    int temp;
    for (idx = 0; idx < arrSize / 2; idx++)
    {
        temp = arr[idx];
        arr[idx] = arr[arrSize - 1 - idx];
        arr[arrSize - 1 - idx] = temp;
    }
}
void printArray(int arr[], int arrSize)
{
    int i;

    for (i = 0; i < arrSize; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void removeOdd(int arr[], int &arrSize)
{
    int i = 0, j = 0;
    while (i < arrSize)
    {
        if (arr[i] % 2 == 0)
        {
            arr[j] = arr[i];
            j++;
        }
        i++;
    }

    arrSize = j;
}

void splitParity(int arr[], int arrSize)
{
    int i = 0, j = arrSize - 1;
    int temp;
    while (i < j)
    {
        while (arr[i] % 2 == 1)
        {
            i++;
        }
        while (arr[j] % 2 == 0)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
