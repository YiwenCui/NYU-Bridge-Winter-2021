#include <iostream>
using namespace std;

void printTriangle(int n);
void printOpositeTriangle(int n);
void printRuler(int n);

int main()
{
    cout<<"#1:"<<endl;
    printTriangle(4);
    cout<<endl;
    cout<<"#2:"<<endl;
    printOpositeTriangle(4);
    cout<<endl;
    cout<<"#3:"<<endl;
    printRuler(4);
    cout<<endl;
    return 0;
}
void printTriangle(int n)
{
    if (n == 1)
    {
        cout << "* ";
        cout << endl
             << endl;
    }
    else
    {
        printTriangle(n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << "* ";
        }

        cout << endl
             << endl;
    }
}
void printOpositeTriangle(int n)
{
    if (n == 1)
    {
        cout << "* ";
        cout << endl
             << endl;
        cout << "* ";
        cout << endl
             << endl;
    }

    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << "* ";
        }
        cout << endl
             << endl;

        printOpositeTriangle(n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << "* ";
        }
        cout << endl
             << endl;
    }
}

void printRuler(int n)
{
    int i, j;
    if (n == 1)
    {
        cout << "- " << endl
             << endl;
    }
    else
    {
        printRuler(n - 1);
        for (i = 0; i < n; i++)
        {
            cout << "- ";
        }
        cout << endl
             << endl;
        printRuler(n - 1);
    }
}