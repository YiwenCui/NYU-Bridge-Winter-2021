#include <iostream>
using namespace std;

int jumpOnWhich(int arr[], int arrSize, int &sum);

int main()
{
    int sum = 0;
    int arr[6] = {0, 3, 80, 6, 57, 10};
    int arrSize = 6;

    if (arrSize % 2 == 0)
    {
        jumpOnWhich(arr, arrSize, sum);
        cout << sum + arr[arrSize - 1];
    }

    else{
        jumpOnWhich(arr, arrSize, sum);
        cout << sum;
    }
}
int jumpOnWhich(int arr[], int arrSize, int &sum)
{
    int res;
    if (arrSize == 1)
    {
        res = arr[arrSize - 1];
        return res;
    }
    else
    {
        res = jumpOnWhich(arr, arrSize - 1, sum);

        if (arrSize % 2 == 0)
        {
            res = arr[arrSize - 1];
        }

        else
        {
            if (res > arr[arrSize - 1])
            {
                sum += arr[arrSize - 1];
            }
            else
            {

                sum += res;
            }
            res = arr[arrSize - 1];
        }
    }
    return res;
}