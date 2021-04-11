#include <iostream>
using namespace std;

void printSingleLineDes(int totalColumnNum, int spacePadding)
{
    for (int columnCount = 1; columnCount <= totalColumnNum; columnCount++)
    {
        if (columnCount >= spacePadding && columnCount <= totalColumnNum - spacePadding)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
    return ;
}

void printSingleLineAsc(int x, int totalColumnNum, int spacePadding)
{
    for (int columnCount = 1; columnCount <= totalColumnNum; columnCount++)
    {
        if (columnCount >= x - spacePadding && columnCount <= x + spacePadding)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
    return ;
}

void printSingleLineNew(int lineLength, int spacePadding)
{
    for (int i = 1; i <= lineLength; i++)
    {
        if (i > spacePadding && i <= lineLength - spacePadding)
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
    }
    return ;
}

void printSingleLine(int x, int tcn, int sp, bool IfDes){
    if (IfDes==true){
        printSingleLineDes(tcn, sp);
    }
    else
    {
        printSingleLineAsc(x,tcn,sp);
    }
    
}

int main()
{
    int n;
    int lineCount;
    int totalColumnNum;
    int spacePadding;

    cout << "Please enter a positive integer: ";
    cin >> n;

    totalColumnNum = 2 * n - 1;

    for (lineCount = 1; lineCount <= n; lineCount++)
    {
        spacePadding = lineCount - 1;
        printSingleLineNew(totalColumnNum, spacePadding);
        cout << endl;
    }

    for (lineCount = 1; lineCount <= n; lineCount++)
    {
        spacePadding = n - lineCount;
        printSingleLineNew(totalColumnNum, spacePadding);
        cout << endl;
    }
    return 0;
}
