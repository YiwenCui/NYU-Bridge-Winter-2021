#include <iostream>
using namespace std;

int main()
{
    int n, columnCount, lineCount;

    cout << "Please enter a positive integer: " << endl;
    cin >> n;

    columnCount = 1;
    lineCount = 1;

    for (lineCount = 1; lineCount <= n; lineCount++)
    {
        columnCount = 1;
        for (columnCount = 1; columnCount <= n; columnCount++)
        {
            cout << columnCount * lineCount << '\t';
        }
        cout << endl;
    }
    return 0;
}