#include<iostream>
using namespace std;

int main(){
    int n;
    int linecount, columncount, spacing;
    char currentChar;

    cout<<"Please enter an integer: "<<endl;
    cin>>n;

    cout<<"Please enter a char: "<<endl;
    cin>>currentChar;


    for (linecount=1; linecount<=n;linecount++){
        spacing = n-linecount;
        i=1;
        for(columncount=1; columncount<=n; columncount++){
            
            if(columncount<=spacing){
                cout<<"  ";
            }
            else{
                cout<<char(i)++;
                cout<<" ";
            }

            
            
        }
        cout<<endl;
    }

    return 0;
}