#include <iostream>
using namespace std;

int main()
{
    int initialSpace, columnCount, lineCount;
    char inputLetter, lastLetter;
    int n, totalLines;

    cout<<"Please enter a letter: ";
    cin>> inputLetter;

    n=(inputLetter - 'a')+1;
    totalLines=2*n -1;

    for(lineCount=1,lastLetter='a';lineCount<=n;lineCount++,lastLetter++){
        for(columnCount=1;columnCount<=n-lineCount;columnCount++){
            cout<<" ";
        }
        char currentLetter;
        for(columnCount=2,currentLetter='a';currentLetter<=lastLetter;currentLetter++){
            cout<<currentLetter<<" ";
        }
    
    cout<<endl;

    }
    for(lineCount=n+1,lastLetter=inputLetter -1;lineCount<=totalLines;lineCount++,lastLetter--){
        for(columnCount=1;columnCount<=lineCount-n;columnCount++){
            cout<<" ";
        }
        char currentLetter;
        for(columnCount=2,currentLetter='a';currentLetter<=lastLetter;currentLetter++){
            cout<<currentLetter<<" ";
        }
    
    cout<<endl;

    }

    return 0;

}