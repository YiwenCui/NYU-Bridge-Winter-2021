#include <iostream>
#include <string>
using namespace std;

bool ifDigit(int num);
bool shouldPrint(int j, string y);
bool shouldPrintX(int i, int j, string userInput);
void printX(int numOfX);
void printNonInt(int i, int j, string y);

int main()
{
    string userInput;
    int i;

    cout << "Please enter a line of text: " << endl;
    getline(cin, userInput);

    for (i = 0; i < userInput.length(); i++)
    {
        if (ifDigit(userInput[i]) == true)
        {
            int j;

            for (j = i; j < userInput.length(); j++)
            {
                if (shouldPrint(j, userInput) == true)
                {
                    if (shouldPrintX(i, j, userInput) == true)
                    {
                        int numOfX = j - i;
                        if (j == userInput.length() - 1)
                        {
                            numOfX += 1;
                        }
                        printX(numOfX);
                        cout << " ";
                    }
                    else
                    {
                        printNonInt(i, j, userInput);
                    }
                    break;
                }
            }
            i = j;
        }

        else
        {
            cout << userInput[i];
        }
    }
    return 0;
}

bool ifDigit(int num)
{
    if (num >= '0' && num <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printX(int numOfX)
{

    for (int idx = 0; idx < numOfX; idx++)
    {
        cout << "X";
    }
}

void printNonInt(int i, int j, string y)
{
    for (int idx = i; idx <= j; idx++)
    {
        cout << y[idx];
    }
}

bool shouldPrint(int j, string y)
{
    return ifDigit(y[j]) == false || j == y.length() - 1;
}

bool shouldPrintX(int i, int j, string userInput)
{
    return (i == 0 || userInput[i - 1] == ' ') && (userInput[j] == ' ' || (j == userInput.length() - 1 && userInput[j] >= '0' && userInput[j] <= '9'));
}