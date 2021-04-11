#include<iostream>
using namespace std;

int main(){
    int firstNumber, secondNumber;
    int addition, subtraction, multiplication;
    double division;
    int div, mod;

    cout<<"Please enter two positive integer, separated by a space:" <<endl;
    cin>>firstNumber >>secondNumber;

    addition = firstNumber + secondNumber;
    subtraction = firstNumber - secondNumber;
    multiplication = firstNumber * secondNumber;
    division = double(firstNumber) / double(secondNumber);
    div = firstNumber / secondNumber;
    mod = firstNumber % secondNumber;

    cout<<firstNumber<<" + "<<secondNumber<<" = "<<addition<<endl;
    cout<<firstNumber<<" - "<<secondNumber<<" = "<<subtraction<<endl;
    cout<<firstNumber<<" * "<<secondNumber<<" = "<<multiplication<<endl;
    cout<<firstNumber<<" / "<<secondNumber<<" = "<<division<<endl;

    cout<<firstNumber<<" div "<<secondNumber<<" = "<<div<<endl;
    cout<<firstNumber<<" mod "<<secondNumber<<" = "<<mod<<endl;

    return 0;
}
