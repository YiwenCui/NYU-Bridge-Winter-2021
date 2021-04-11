#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main()
{
    int arr[4] = {2,-1,3,10};
    cout << sumOfSquares(arr, 4)<<endl;
    if(isSorted(arr, 4)==0){
        cout<<"false"<<endl;
    }
    else{
        cout<<"true"<<endl;
    }
    return 0;
}

int sumOfSquares(int arr[], int arrSize)
{
    int sum = 0;
    if (arrSize == 1)
    {
        sum = arr[arrSize - 1] * arr[arrSize - 1];
    }
    else
    {
        int newSum = sumOfSquares(arr, arrSize - 1);
        int lastNumSquare = arr[arrSize - 1] * arr[arrSize - 1];
        sum = newSum + lastNumSquare;
    }

    return sum;
}

bool isSorted(int arr[], int arrSize)
{
    bool res = false;
    if (arrSize == 1)
    {
        return true;
    }
    else
    {
        res = isSorted(arr, arrSize - 1);
        if(arr[arrSize-1]>=arr[arrSize-2] && res == true){
            return true;
        }
        else{
            return false;
        }
    }    
}