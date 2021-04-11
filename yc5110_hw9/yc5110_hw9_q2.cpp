#include <iostream>
#include <string>
#include <vector>
using namespace std;
string stripNonLetter(string x);
bool isLetter(char a);
string stringWithOnlyLowercase(string y);
void finalVector(string c, vector<char> &z);

int main()
{
    string firstStr, secondStr;
    cout << "Please enter your first string:" << endl;
    getline(cin, firstStr);
    cout << "Please enter your secondstring:" << endl;
    getline(cin, secondStr);

    vector<char> a;
    for (int i = 0; i < 26; i++)
    {
        a.push_back(0);
    }
    vector<char> b;
    for (int i = 0; i < 26; i++)
    {
        b.push_back(0);
    }

    string a1 = stripNonLetter(firstStr);
    string a2 = stringWithOnlyLowercase(a1);
    string b1 = stripNonLetter(secondStr);
    string b2 = stringWithOnlyLowercase(b1);

    finalVector(a2, a);
    finalVector(b2, b);

    bool isAnagrams = true;
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            isAnagrams = false;
            break;
        }
    }
    if (isAnagrams == false)
    {
        cout << "These two strings are not anagrams";
    }
    else
    {
        cout << "These two strings are anagrams";
    }
    

    return 0;
}

string stripNonLetter(string x)
{
    string newString = "";
    for (int i = 0; i < x.length(); i++)
    {
        if (isLetter(x[i]) == true)
        {
            newString += x[i];
        }
    }
    return newString;
}

bool isLetter(char a)
{
    return ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'));
}

string stringWithOnlyLowercase(string y)
{
    for (int i = 0; i < y.length(); i++)
    {
        if (y[i] >= 'A' && y[i] <= 'Z')
        {
            y[i] += 'a' - 'A';
        }
    }
    return y;
}

void finalVector(string c, vector<char> &z)
{
    for (int i = 0; i < c.length(); i++)
    {
        z[c[i] - 'a'] += 1;
    }
}