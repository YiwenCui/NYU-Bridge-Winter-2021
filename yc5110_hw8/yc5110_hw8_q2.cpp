#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main()
{
    string word;
    cout << "Please enter a word: ";
    cin >> word;

    if (isPalindrome(word) == true)
    {
        cout << word << " is a palindrome";
    }
    else
    {
        cout << word << " is not a palindrome";
    }

    return 0;
}

bool isPalindrome(string str)
{
    int idx;
    string reversedStr;

    for (idx = str.length() - 1; idx >= 0; idx--)
    {
        reversedStr += str[idx];
    }

    if (reversedStr == str)
    {
        return true;
    }
    else
    {
        return false;
    }
}
