#include <iostream>
using namespace std;

int findFirstPosition(int arr[], int arrSize, int elem);
int main()
{

    int arr[10]={2,15,3,8,3,10,6,23,12,32};
    cout<<findFirstPosition(arr, 10, 3);
    return 0;
}

int findFirstPosition(int arr[], int arrSize, int elem)
{
    if (arrSize == 1)
    {
        if (elem == arr[arrSize - 1])
        {
            return arrSize - 1;
        }

        else
        {
            return -1;
        }
    }

    else
    {
        int a = findFirstPosition(arr, arrSize - 1, elem);
        if (a == -1)
        {
            if (elem == arr[arrSize - 1])
            {
                return arrSize - 1;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return a;
        }
    }
    return 0;
}
