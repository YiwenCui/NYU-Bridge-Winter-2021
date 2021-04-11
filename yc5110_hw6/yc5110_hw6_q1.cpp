#include <iostream>
using namespace std;

int fib(int n);
int main()
{
    int inputInt, output;

    cout << "Please enter a positive integer: ";
    cin >> inputInt;

    output = fib(inputInt);

    cout << output;

    return 0;
}

int fib(int n)
{
    int a = 1, b = 1, c, i;

    if (n == 1 || n == 2)
    {
        return a;
    }

    for (i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}