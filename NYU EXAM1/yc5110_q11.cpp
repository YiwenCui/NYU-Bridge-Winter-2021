#include <iostream>
using namespace std;

int main(){
    char lastLetter, inputChar;
    int totalLineCount, totalColumnCount;
    int columnCount,lineCount,space;
    char currentLetter;
    char lastLetterUpper;

    cout<<"Please enter a lower-case letter: "<<endl;
    cin>>inputChar;

    totalLineCount=inputChar-'a'+1;
    totalColumnCount=2*totalLineCount-1;

    for(lineCount=1,lastLetter='a';lineCount<=totalLineCount;lineCount++,lastLetter++){
        space=totalLineCount-lineCount;
        
        for (columnCount=1;columnCount<=space;columnCount++){
            cout<<" ";
        }
        
        for (columnCount=2;columnCount<=2*lineCount;columnCount++){
            if (lineCount%2==0){
                lastLetterUpper=lastLetter-32;
                
                cout<<lastLetterUpper;
            }
            else{
                cout<<lastLetter;
            }
            
        }
    cout<<endl;   
    }
    

    return 0;

}
