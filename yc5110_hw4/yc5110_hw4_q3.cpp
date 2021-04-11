#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n; //user's input as an integer
    int x; //exponent

    cout << "Enter decimal number: " << endl;
    cin >> n;

    x = 0;

    while (pow(2, x) <= n)
    {
        x++;
    }
    
    if(n==0){
        cout<<0;
    }

    while (n > 0)
    {
        if (n - pow(2, x - 1) >= 0)
        {
            cout << "1";
            n = n - pow(2, x - 1);
        }
        else
        {
            cout << "0";
        }

        x--;
    }

    while (x > 0)
    {
        cout << "0";
        x--;
    }

    return 0;
}