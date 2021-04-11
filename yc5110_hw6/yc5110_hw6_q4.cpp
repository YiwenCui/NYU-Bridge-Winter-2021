#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);
int main()
{
    int inputInt;
    cout << "Please enter a positive integer >=2: ";
    cin >> inputInt;

    printDivisors(inputInt);

    return 0;
}

void printDivisors(int num)
{
    int i, j;
    int squareRoot = pow(num, 1.0 / 2);
    cout << squareRoot << endl;

    for (i = 1; i <= squareRoot; i++)
    {
        if (num % i == 0)
        {
            cout << i << " ";
        }
    }
    
    for (j =squareRoot; j >= 1; j--)
    {
        if (num % j == 0 && num/j != i-1)
        {
            cout << num / j << " ";
        }
    }
}
