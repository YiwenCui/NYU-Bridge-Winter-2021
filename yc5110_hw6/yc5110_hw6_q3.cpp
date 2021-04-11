#include <iostream>
using namespace std;

double eApprox(int n);
int main()
{
    int n;
    cout.precision(30);

    for (int n = 1; n <= 15; n++)
    {
        cout << "n= " << n << '\t' << eApprox(n) << endl;
    }

    return 0;
}

double eApprox(int n)
{
    double sum = 0.0;
    int i;
    double prevFrac = 1.0;

    for (i = 1; i <= n; i++)
    {
        double currentFrac;

        currentFrac = prevFrac * (1.0 / i);
        prevFrac = currentFrac;

        // for (num = 1; num <= i; num++)
        // {
        //     factorial*=num;
        // }
        sum += currentFrac;
    }

    sum = sum + 1;

    return sum;
}