#include <iostream>
using namespace std;

void makeXorArray(int *srtArr1, int n1, int *srtArr2, int n2, int **outXorArr, int *outN);
void printArray(int arr[], int arrSize);
bool inArray(int arr[], int arrSize, int a);

int main()
{
    int srtArr1[6] = {1, 2, 3, 5, 7, 8};
    int srtArr2[4] = {2, 5, 6, 9};
    int *xorArr=nullptr;
    int **outXorArr = &xorArr;
    int xorArrSize=10;
    int* outN = &xorArrSize;

    makeXorArray(srtArr1, 6, srtArr2, 4, outXorArr, outN);

    cout<< "srtArr1: ";
    printArray(srtArr1, 6);

    cout << "srtArr2: ";
    printArray(srtArr2, 4);

    cout << "xorArr: ";
    printArray(xorArr, xorArrSize);

    delete[] xorArr;
    return 0;
}
void makeXorArray(int *srtArr1, int n1, int *srtArr2, int n2, int **outXorArr, int *outN)
{
    int *newArray = new int[n1 + n2];
    int i = 0, j = 0, k=0;
    while (i < n1 && j < n2)
    {
        if (srtArr1[i] == srtArr2[j])
        {
            i++;
            j++;
        }
        else if (srtArr1[i] < srtArr2[j])
        {
            newArray[k] = srtArr1[i];
            if (i==n1-1 && j==n2-1){
                newArray[k]=srtArr2[n2-1];
            }
            i++;
            k++;
            
        }
        else if(srtArr1[i] > srtArr2[j])
        {
            newArray[k] = srtArr2[j];
            if (i==n1-1 && j==n2-1){
                newArray[k]=srtArr1[i];
            }
            j++;
            k++;
            
        }
        
    }
    *outXorArr = newArray;
    *outN =k;
}


void printArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}