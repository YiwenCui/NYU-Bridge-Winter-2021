#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TO_LOWER_CASE = 'a' - 'A';

int numOfWordsInString(string userInput);
string stripNonLetter(string userInput);
string toLowerLetter(string x);
bool isLowercase(char a);
bool isUppercase(char a);

int main()
{
    string userInput;
    int i;
    cout << "Please enter a line of text:" << endl;
    getline(cin, userInput);
    cout << numOfWordsInString(userInput) << '\t' << "words" << endl;
    string a = stripNonLetter(userInput);
    string b = toLowerLetter(a);

    // #1 option,runtime o(26n), O(n):
    // char x;
    // int count;
    // for (x = 'a'; x <= 'z'; x++)
    // {

    //     count = 0;
    //     for (int j = 0; j < b.length(); j++)
    //     {
    //         if (b[j]==x)
    //         {
    //             count++;
    //         }
    //     }
    //     if (count!=0){
    //         cout<<count<<'\t'<<x<<endl;
    //     }
    // }

    // #2 option, using vector, o(n), O(n);
    vector<int> num;
    for (int i = 0; i <= 25; i++){
        num.push_back(0);
    }
    for (int j=0;j<b.length();j++){
        int c = num[b[j]-'a']++;
    }
    for (int i = 0; i <= 25; i++){
        if (num[i]!=0){
            cout<<num[i]<<'\t'<<char('a'+i)<<endl;
        }
    }

        return 0;
}

int numOfWordsInString(string userInput)
{
    int numOfWords = 0;
    for (int i = 0; i < userInput.length(); i++)
    {
        if (userInput[i] == '.' || userInput[i] == ' ' || userInput[i] == ',' || i == userInput.length() - 1)
        {
            numOfWords++;
        }
    }
    return numOfWords;
}

string stripNonLetter(string userInput)
{
    string newstrippedNonLetter = "";
    for (int i = 0; i < userInput.length(); i++)
    {
        if (isUppercase(userInput[i]) == true || isLowercase(userInput[i]) == true)
        {
            newstrippedNonLetter += userInput[i];
        }
    }
    return newstrippedNonLetter;
}

bool isLowercase(char a)
{
    return (a >= 'a' && a <= 'z');
}
bool isUppercase(char a)
{
    return (a >= 'A' && a <= 'Z');
}

string toLowerLetter(string x)
{
    for (int i = 0; i < x.length(); i++)
    {
        if (isUppercase(x[i]) == true)
        {
            x[i] += TO_LOWER_CASE;
        }
    }
    return x;
}