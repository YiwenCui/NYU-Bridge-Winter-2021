#include <iostream>
using namespace std;

int main()
{
    int inputInt, sum;
    int num, currentDigit;

    sum = 0;

    cout << "Please enter an integer: " << endl;
    cin >> inputInt;

    for (num = inputInt; num > 0; num = num / 10)
    {
        currentDigit = num % 10;
        sum += currentDigit;
    }

    cout << sum;

    return 0;
}
