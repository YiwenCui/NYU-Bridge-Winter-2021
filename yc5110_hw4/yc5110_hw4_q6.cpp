#include <iostream>
using namespace std;

int main()
{
    int n;
    int num, numCopy, currentDigit;
    int evenCount = 0, oddCount = 0;

    cout << "Please enter a positive integer n: " << endl;
    cin >> n;
    num = 1;

    for (num = 1; num <= n; num++)
    {
        numCopy = num;
        evenCount = 0;
        oddCount = 0;
        while (numCopy > 0)
        {
            currentDigit = numCopy % 10;
            if (currentDigit % 2 == 0)
            {
                evenCount++;
            }
            else if (currentDigit % 2 == 1)
            {
                oddCount++;
            }
            numCopy = numCopy / 10;
        }

        if (evenCount > oddCount)
        {
            cout << num << endl;
        }
    }
    return 0;
}