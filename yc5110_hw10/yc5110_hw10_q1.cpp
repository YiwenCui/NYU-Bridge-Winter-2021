#include <iostream>
#include <string>
using namespace std;

string *createWordsArray(string sentence, int &outWordsArrSize);

int main()
{
    string userInput;
    int outWordsArrSize;
    string *ptrToArray = nullptr;
    cout << "Please enter a sentence, separate by a single space: " << endl;
    getline(cin, userInput);

    ptrToArray = createWordsArray(userInput, outWordsArrSize);
    cout<<"[";
    for (int i =0; i<outWordsArrSize; i++){
        cout<<'"'<< ptrToArray[i]<<'"';
        if (i<outWordsArrSize-1){
            cout<<" , ";
        }
    }
    cout<<"]";

    delete [] ptrToArray;
    
    return 0;
}

string *createWordsArray(string sentence, int &outWordsArrSize)
{
    int arrSize = 0;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == ' ' || i == sentence.length() - 1)
        {
            arrSize++;
        }
    }
    string *arr = new string [arrSize];

    for (int i = 0, j = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ' && i != sentence.length())
        {
            arr[j] += sentence[i];
        }
        else
        {
            j++;
        }
    }

    outWordsArrSize = arrSize;
    return arr;
}