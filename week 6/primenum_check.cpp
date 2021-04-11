#include<iostream>
using namespace std;

int main(){
    int inputNum, division, mod;
    bool primeNum =true;

    cout<<"Please enter an integer: "<<endl;
    cin>>inputNum;

    for (division=2;division<inputNum;division++){
        mod=inputNum%division;
        if (mod==0){
            cout<<"This is not a prime number."<<endl;
            primeNum=false;
            break;
        }

    }
    if(primeNum==true){
        cout<<"This is a prime number."<<endl;
    }

    return 0;
}