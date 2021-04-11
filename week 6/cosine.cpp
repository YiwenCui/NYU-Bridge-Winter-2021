#include <iostream>
using namespace std;
#include <cmath>

double quad_cos(double x, int n);
double liner_cos(double x, int n);
int factorial(int a);

int main()
{
    double x;
    int n;
    cout << "Please enter a double and an integer: " << endl;
    cin >> x >> n;

    cout.precision(10);
    cout << quad_cos(x, n)<<'\t' << liner_cos(x, n)<<endl;

    return 0;
}

double liner_cos(double x, int n)
{
    int k, sign;
    double currentTerm, currentFactorial, currentPow , sum = 0;
    
    for (k = 0, sign = 1; k <= n-1; k++, sign *= -1)
    {
        if (k == 0)
        {
            currentPow = 1;
            currentFactorial=1;
        }
        else
        {
            currentPow *= x * x;
            currentFactorial*= 2 * k * (2 * k - 1);
        }
        // cout<<currentFactorial<<'\t';
        // cout<<currentPow<<'\t';
        currentTerm = sign * (currentPow / currentFactorial);
        
        sum += currentTerm;
    }
    return sum;
}

double quad_cos(double x, int n)
{
    int exponent, count;
    double num, sum = 1.0;
    for (exponent = 2, count = 1; count < n; exponent += 2, count++)
    {
        if (count % 2 == 1)
        {
            num = -pow(x, exponent) / factorial(exponent);
        }
        else
        {
            num = pow(x, exponent) / factorial(exponent);
        }
        sum += num;
    }
    return sum;
}

int factorial(int a)
{
    int i, fac = 1;
    for (i = 1; i <= a; i++)
    {
        fac *= i;
    }
    return fac;
}
