#include <iostream>
#include <string>
using namespace std;

int *findMissing(int arr[], int n, int &resArrSize);
void printMissingArray(int arr[], int n);

int main()
{
    int arr1[6] = {3,1,3,0,6,4};
    int arrSize = 6;
    int missingSize = 1;
    int *missingArr = nullptr;

    missingArr = findMissing(arr1, arrSize, missingSize);
    printMissingArray(missingArr, missingSize);

    delete [] missingArr;

    return 0;
}

int *findMissing(int arr[], int n, int &resArrSize)
{
    int missingCount = 0;
    int *arrWithAllZero = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arrWithAllZero[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        arrWithAllZero[arr[i]]++;
    }

    for (int i = 0; i <= n; i++)
    {
        if (arrWithAllZero[i] == 0)
        {
            missingCount++;
        }
    }
    resArrSize = missingCount;

    int *missingArr = new int[missingCount];
    int j = 0;
    for (int i = 0; i <= n; i++)
    {
        if (arrWithAllZero[i] == 0)
        {
            missingArr[j] = i;
            j++;
        }
    }
    delete [] arrWithAllZero;
    return missingArr;
}

void printMissingArray(int arr[], int n)
{
    cout << '[';
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i != n - 1)
        {
            cout << ", ";
        }
    }
    cout << ']';
}