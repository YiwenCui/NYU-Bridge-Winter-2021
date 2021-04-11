#include <iostream>
using namespace std;

double findMedian(int arr[], int n);

int main()
{
    int arr[8] = {1, 2, 2, 3, 4, 6, 7, 8};
    double a = findMedian(arr, 8);
    cout << a;

    return 0;
}
double findMedian(int arr[], int n)
{
    int *countArray = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        countArray[arr[i]]++;
    }
    int count = 0;

    if (n % 2 == 1)
    {
        for (int i = 0; i < n + 1; i++)
        {
            count += countArray[i];
            if (count == (n + 1) / 2)
            {
                return i;
            }
        }
    }

    else
    {
        for (int i = 0; i < n + 1; i++)
        {
            count += countArray[i];

            if (count == n / 2)
            {
                return double(i + i + 1) / 2;
            }
        }
    }
}