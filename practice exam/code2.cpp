#include <iostream>
using namespace std;

int main()
{
    int inputInt, n, num;
    int currentDigit;
    int factorial;
    int sum;

    sum = 0;
    factorial = 1;

    cout << "Please enter a positive integer: " << endl;
    cin >> inputInt;

    if (inputInt==0){
        cout<<inputInt << " is not a factorion" << endl;

    }
    else{
        for (num = inputInt; num != 0; num = num / 10)
        {
            currentDigit = num % 10;
            factorial = 1;
            for (n = currentDigit; n >= 1; n--)
            {
                factorial *= n;
            }

            sum += factorial;
        }

        if (sum == inputInt)
        {
            cout << inputInt << " is a factorion" << endl;
        }
        else
        {
            cout << inputInt << " is not a factorion" << endl;
        }
    }
    return 0;
}