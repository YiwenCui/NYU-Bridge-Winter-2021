#include <iostream>
using namespace std;

int main()
{
    int columnCount, lineCount, inputInt;
    int spacePadding, totalColumns, totalLines;

    cout << "Please enter an integer: " << endl;
    cin >> inputInt;
    totalColumns = 2 * inputInt - 1;
    totalLines = 2 * inputInt - 1;

    for (lineCount = 1; lineCount <= inputInt; lineCount++)
    {
        for (columnCount = 1; columnCount <= totalColumns; columnCount++)
        {
            spacePadding = inputInt - lineCount;

            if (columnCount <= spacePadding || columnCount > totalColumns - spacePadding)
            {
                cout << " ";
            }
            else
            {
                if (lineCount % 2 == 1)
                {
                    if (columnCount % 2 == 0)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else
                {
                    if (columnCount % 2 == 1)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }

    for (lineCount = inputInt + 1; lineCount <= totalLines; lineCount++)
    {
        for (columnCount = 1; columnCount <= totalColumns; columnCount++)
        {
            spacePadding = lineCount - inputInt;
            if (columnCount <= spacePadding || columnCount > totalColumns - spacePadding)
            {
                cout << " ";
            }
            else
            {
                if (lineCount % 2 == 1)
                {
                    if (columnCount % 2 == 0)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else
                {
                    if (columnCount % 2 == 1)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}