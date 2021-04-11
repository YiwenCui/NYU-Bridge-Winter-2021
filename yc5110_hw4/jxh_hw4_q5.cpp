#include<iostream>
using namespace std;

int main(){
    int n;
    int line,column,b;

    line=0, column=0;   

    cout<<"Please enter a positive integer: ";
    cin>>n;

    int total_column = 2*n-1;

    while(line<n){
        column=0;
        int space_padding = (line-1);
        while(column<=total_column){
            if (column > space_padding && column < total_column - space_padding) {
                cout<<"*";
            } else {
                cout<<" ";
            }
            column++;            
        }       
        
        line++;
        cout<<endl;        
    }
    
    return 0;

}