#include<iostream>
using namespace std;

int main(){
    int inputInt, columnCount, lineCount; 
    int totalColumn;

    cout<<"Please enter an integer, greater or equal to 2: "<<endl;
    cin>>inputInt;

    totalColumn=2*inputInt -1;

    for(lineCount=1; lineCount<=inputInt; lineCount++){
        for(columnCount=1; columnCount<=totalColumn; columnCount++){
            if(lineCount==1){
                cout<<"*";
            }
            else if (columnCount==lineCount || columnCount == totalColumn+1-lineCount){
                cout<<"*";
            }
            else{
                cout<<" ";
            }    
        }
        cout<<endl;
    }
    return 0;
}