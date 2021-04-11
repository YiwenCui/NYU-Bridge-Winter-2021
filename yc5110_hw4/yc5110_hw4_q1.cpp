#include <iostream>
using namespace std;

int main(){

    //#1. while loop version
    int n, counter;
    int k; //initialize k is 1, then the first even integer will be 2k

    cout<<"Please enter a positive integer: ";
    cin>>n;

    counter = 0;
    k = 1;

    while(counter < n){
        cout<< 2*k <<endl;
        k++;
        counter++;
    }


    //#2. for loop version
    cout<<"Please enter a positive integer: ";
    cin>>n;

    k=1;

    for (counter = 0; counter<n; counter++){
        cout<<2*k<<endl;
        k++;
    }

    
    return 0;
}