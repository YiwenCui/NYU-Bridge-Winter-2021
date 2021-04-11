#include <iostream>
using namespace std;

const int I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000;

int main()
{
    int n; // user's input as an integer.
    cout << "Enter decimal number: " << endl;
    cin >> n;

    cout<<n<<" is ";
    
    while (n >= M)
    {
        n = n - M;
        cout << "M";
    }
    while (n >= D)
    {
        n = n - D;
        cout << "D";
    }
    while (n >= C)
    {
        n = n - C;
        cout << "C";
    }
    while (n >= L)
    {
        n = n - L;
        cout << "L";
    }
    while (n >= X)
    {
        n = n - X;
        cout << "X";
    }
    while (n >= V)
    {
        n = n - V;
        cout << "V";
    }
    while (n >= I)
    {
        n = n - I;
        cout << "I";
    }

    return 0;
}