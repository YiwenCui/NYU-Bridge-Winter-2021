#include <iostream>
using namespace std;

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

int main()
{
    int *mergedArr = nullptr;
    int arrToBeSorted[7] = {1, 3, 6, 7, 2, 4, 5};
    int high = 6, low = 0;

    mergeSort(arrToBeSorted, low, high);

    for (int i = 0; i <= 5; i++)
    {
        cout << mergedArr[i] << " ";
    }
    return 0;
}

void merge(int arr[], int lowLeft, int lowRight, int highRight)
{
    int highLeft = lowRight + 1;
    int size = highRight + 1;
    int *mergedArr;
    mergedArr = new int[size];

    for (int i = 0, j = highLeft, k = 0; i <= j && k < size; k++)
    {
        if (lowLeft < highLeft)
        {
            mergedArr[k] = lowLeft;
            i++;
        }
        else
        {
            mergedArr[k] = highLeft;
            j++;
        }
    }
}

void mergeSort(int arr[], int low, int high)
{
    int lowRight = (low + high) / 2;

    if (low == high)
    {
        return;
    }
    else{
        mergeSort(arr,low,lowRight);
        mergeSort(arr, lowRight+1, high);
        merge(arr, low, lowRight, high);
    }
}