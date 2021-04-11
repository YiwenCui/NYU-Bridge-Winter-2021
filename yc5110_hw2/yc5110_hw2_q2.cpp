#include<iostream>
using namespace std;

const int CENTS_PER_QUARTER = 25;
const int CENTS_PER_DIME = 10;
const int CENTS_PER_NICKEL = 5;
const int CENTS_PER_PENNY = 1;
const int CENTS_PER_DOLLAR = 100;
int main(){
    int amountOfDollars, amountOfCents;
    int totalAmountInCents;
    int numberOfQuarters, numberOfDimes, numberOfNickels, numberOfPennies;
    int remainingCentsAfterFullQuarter, remainingCentsAfterFullDime,remainingCentsAfterFullNickel;
    

    cout<<"Please enter your amount in the format of dollars and cents seprated by a space:"<<endl;
    cin>>amountOfDollars>> amountOfCents;

    totalAmountInCents = amountOfDollars * CENTS_PER_DOLLAR + amountOfCents*CENTS_PER_PENNY;
    numberOfQuarters = totalAmountInCents / CENTS_PER_QUARTER;
    remainingCentsAfterFullQuarter = totalAmountInCents % CENTS_PER_QUARTER;
    numberOfDimes = remainingCentsAfterFullQuarter / CENTS_PER_DIME;
    remainingCentsAfterFullDime = remainingCentsAfterFullQuarter % CENTS_PER_DIME;
    numberOfNickels = remainingCentsAfterFullDime / CENTS_PER_NICKEL;
    remainingCentsAfterFullNickel = remainingCentsAfterFullDime % CENTS_PER_NICKEL;
    numberOfPennies = remainingCentsAfterFullNickel;


    cout<< amountOfDollars <<" dollars and " <<amountOfCents <<" cents are: "<<endl;
    cout<< numberOfQuarters <<" quarters, "<< numberOfDimes <<" dimes, " << numberOfNickels <<" nickels and "<< numberOfPennies << " pennies";

    return 0;
}