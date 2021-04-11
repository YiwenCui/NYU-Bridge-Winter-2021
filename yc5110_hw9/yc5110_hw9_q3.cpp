#include <iostream>
#include <string>
using namespace std;

int *getPosNums1(int *arr, int arrSize, int &outPosArrSize);
int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr);
void getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize);
void getPosNums4(int *arr, int arrSize, int **outPosArr, int *outPosArrSizePtr);
void printArray(int *arr, int arrSize);

int main()
{
    //#1 func test:
    int outPosArrSize1 = 6;
    int arrSize1 = 6;
    int arr1[6] = {3, -1, -3, 0, 6, 4};
    int *outPosArr1 = getPosNums1(arr1, arrSize1, outPosArrSize1);
    printArray(outPosArr1, outPosArrSize1);
    delete [] outPosArr1;
    cout << endl;

    //#2 func test:
    int outPosArrSize2 = 6;
    int arrSize2 = 6;
    int *outPosArrSizePtr2 = &outPosArrSize2;
    int arr2[6] = {3, -1, -3, 0, 6, 4};
    int *outPosArr2 = getPosNums2(arr2, arrSize2, outPosArrSizePtr2);
    printArray(outPosArr2, outPosArrSize2);
    delete [] outPosArr2;
    cout << endl;

    //#3 func test:
    int outPosArrSize3 = 6;
    int arrSize3 = 6;
    int *outPosArr3 = nullptr;
    int arr3[6] = {3, -1, -3, 0, 6, 4};
    getPosNums3(arr3, arrSize3, outPosArr3, outPosArrSize3);
    printArray(outPosArr3, outPosArrSize3);
    cout << endl;

    //#4 func test:
    int outPosArrSize4 = 6;
    int *outPosArrSizePtr4 = &outPosArrSize4;
    int arrSize4 = 6;
    int *outPosArr4 = nullptr;
    int **outPosArr5 = &outPosArr4;
    int arr4[6] = {3, -1, -3, 0, 6, 4};
    getPosNums4(arr4, arrSize4, outPosArr5, outPosArrSizePtr4);
    printArray(outPosArr4, outPosArrSize4);

    return 0;
}

int *getPosNums1(int *arr, int arrSize, int &outPosArrSize)
{
    int newArrSize = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            newArrSize++;
        }
    }
    int j = 0;
    int *temp = new int[newArrSize];
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            temp[j] = arr[i];
            j++;
        }
    }
    outPosArrSize = newArrSize;
    

    return temp;
}

int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr)
{
    int newArrSize = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            newArrSize++;
        }
    }
    *outPosArrSizePtr = newArrSize;
    int *temp = new int[newArrSize];
    int j = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            temp[j] = arr[i];
            j++;
        }
    }
    return temp;
}

void getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize)
{
    int newArrSize = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            newArrSize++;
        }
    }
    outPosArrSize = newArrSize;
    int *temp = new int[newArrSize];
    int j = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            temp[j] = arr[i];
            j++;
        }
    }
    
    outPosArr = temp;
    delete[] temp;
}




void getPosNums4(int *arr, int arrSize, int **outPosArr, int *outPosArrSizePtr)
{
    int newArrSize = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            newArrSize++;
        }
    }
    *outPosArrSizePtr = newArrSize;
    int *temp = new int[newArrSize];
    int j = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            temp[j] = arr[i];
            j++;
        }
    }
   
    *outPosArr = temp;
    delete[] temp;
}

void printArray(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
}