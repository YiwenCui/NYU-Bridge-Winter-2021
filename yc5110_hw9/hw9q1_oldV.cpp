#include <iostream>
#include <string>
using namespace std;

const int TO_LOWER_CASE = 'a' - 'A';

int numOfWordsInString(string userInput);
string stripNonLetter(string userInput);
// void stringToArray(string x, char arr[]); not necessary.
bool isLowercase(char a);
bool isUppercase(char a);

int main()
{
    string userInput;
    int i;
    cout << "Please enter a line of text:" << endl;
    //getline(cin, userInput);
    userInput = "I am Yiwen Cui";
    cout << numOfWordsInString(userInput) << '\t' << "words" << endl;
    cout << stripNonLetter(userInput);
    string a = stripNonLetter(userInput);
    
    // char array[a.length()];
    // for (int i = 0; i < a.length(); i++)
    // {
    //    array[i]='0';
    // }
    // stringToArray(a, array);
    // for (int i = 0; i < a.length(); i++)
    // {
    //    cout<<array[i];
    // }


   
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


// void stringToArray(string x, char arr[])
// {
//     for (int i = 0; i < x.length(); i++)
//     {
//         arr[i] = x[i];
//     }
// } not necessary, but want to document it, so commented.