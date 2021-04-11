#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);
int main()
{
    int numOfTree;
    char symbol;

    cout << "please enter the number of trees (int) and desired symbol(char), separate by space: " << endl;
    cin >> numOfTree >> symbol;

    printPineTree(numOfTree, symbol);

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol)
{
    int lineCount, columnCount;

    for (lineCount = 1; lineCount <= n; lineCount++)
    {
        for (columnCount = 1; columnCount <= m + n - lineCount; columnCount++)
        {
            cout << " ";
        }
        for (columnCount = 2; columnCount < 2 * lineCount + 1; columnCount++)
        {
            cout << symbol;
        }
        cout << endl<<endl;
    }
}

void printPineTree(int n, char symbol)
{
    int numOfTree;
    int numOfLines, numOfSpaces;

    for (numOfTree = 1, numOfLines = 2, numOfSpaces = n - numOfTree; numOfTree <= n; numOfTree++, numOfLines++, numOfSpaces--)
    {

        printShiftedTriangle(numOfLines, numOfSpaces, symbol);
    }
}
