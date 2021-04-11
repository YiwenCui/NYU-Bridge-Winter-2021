#include <iostream>
using namespace std;

int main()
{
    int n;
    int lineCount, columnCount;
    int totalColumnNum;
    int spacePadding;

    cout << "Please enter a positive integer: ";
    cin >> n;

    totalColumnNum = 2 * n - 1;

    for (lineCount = 1; lineCount <= n; lineCount++)
    {
        spacePadding = lineCount - 1;
        for (columnCount = 1; columnCount <= totalColumnNum; columnCount++)
        {
            if (columnCount > spacePadding && columnCount <= totalColumnNum - spacePadding)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    for (lineCount = 1; lineCount <= n; lineCount++)
    {
        spacePadding = lineCount - 1;
        for (columnCount = 1; columnCount <= totalColumnNum; columnCount++)
        {
            if (columnCount < n - spacePadding || columnCount > n + spacePadding)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
    return 0;
}
