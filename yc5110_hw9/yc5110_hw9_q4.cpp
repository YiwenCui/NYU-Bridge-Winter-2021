#include <iostream>
using namespace std;
void oddsKeepEvensFlip(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main()
{
    int arr[] = {5, 2, 11, 7, 6, 4, 1, 0, 0, -1};
    int numOfOdd, numOfeven;
    int arrSize = 10;
    oddsKeepEvensFlip(arr, arrSize);

    for (int i = 0; i<arrSize ;i++){
        cout<<arr[i]<<'\t';

    }

    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize)
{
    int oddCount = 0, evenCount = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }

    int *newArr = new int[arrSize];
    for (int i = 0, j = 0, k = arrSize - 1; i < arrSize; i++)
    {
        if (arr[i] % 2 == 1)
        {
            newArr[j] = arr[i];
            j++;
        }
        else
        {
            newArr[k] = arr[i];
            k--;
        }
    }

    arr=newArr;

    // for (int i = 0; i < arrSize; i++)
    // {
    //     cout << newArr[i] << " ";
    // }
    // delete[] newArr;
}
