#include<iostream>
using namespace std;

const int CENTS_PER_QUARTER = 25;
const int CENTS_PER_DIME = 10;
const int CENTS_PER_NICKEL = 5;
const int CENTS_PER_PENNY = 1;
const int CENTS_PER_DOLLAR = 100;
int main(){
    int numberOfQuarters, numberOfDimes, numberOfNickels,numberOfPennies;
    int totalAmount;
    int fullDollars, remainingCents;
    

    cout<< "Please enter number of coins:"<<endl;
    cout<< "# of quarters: ";
    cin>>numberOfQuarters;
    cout<< "# of dimes: " ;
    cin>>numberOfDimes;
    cout<< "# of nickels: ";
    cin>>numberOfNickels;
    cout<< "# of pennies: ";
    cin>>numberOfPennies;

    totalAmount = numberOfQuarters * CENTS_PER_QUARTER + numberOfDimes * CENTS_PER_DIME + numberOfNickels * CENTS_PER_NICKEL + numberOfPennies * CENTS_PER_PENNY;
    fullDollars = totalAmount/CENTS_PER_DOLLAR;
    remainingCents = totalAmount % CENTS_PER_DOLLAR;

    cout<<"The total is "<< fullDollars <<" dollars and "<<remainingCents<<" cents";

    return 0;
} 