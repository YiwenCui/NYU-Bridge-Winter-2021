#include <iostream>
#include <string>
using namespace std;

bool ifAllDigits(string word);

int main()
{
    string userInput;
    int i;

    cout << "Please enter a line of text: " << endl;
    getline(cin, userInput);

    for (i = 0; i < userInput.length(); i++)
    {
        if (userInput[i] >= '0' && userInput[i] <= '9')
        {
            int j;

            for (j = i; j < userInput.length(); j++)
            {
                if (userInput[j] <= '0' || userInput[j] >= '9' || j == userInput.length() - 1)
                {
                    if ((i == 0 || userInput[i-1]==' ') && (userInput[j]==' ' || (j == userInput.length() - 1 && userInput[j] >= '0' && userInput[j] <= '9'))){
                        for (int idx =i; idx<j; idx++){
                            cout<<"X";
                        }
                        cout<<" ";  
                    }
                    else{
                        for (int idx =i; idx<=j; idx++){
                            cout<<userInput[idx];
                        }
                    }
                    break;
                }                
            }
            i=j;
        }

        else
        {
            cout << userInput[i];
        }
    }
    return 0;
}
