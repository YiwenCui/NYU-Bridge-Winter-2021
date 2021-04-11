#include <iostream>
using namespace std;

const int INCHES_PER_FOOT=12, FEETS_PER_YARD=3, INCHES_PER_YARD=36;

int main(){
    int numOfDay=1;
    int numOfInches=-2;
    int sumOfInches=0;
    int numOfTotalYards, numOfTotalFeets, numOfTotalInches;
    int numOfRemainingInches;

    while (numOfInches!=-1){ 
        cout<<"Enter the number of inches the snail traveled in Day #"<< numOfDay<<","<<endl;
        cout<<"or type -1 if they reach the destination"<<endl;
        cin>>numOfInches; 
        if(numOfInches!=-1){
            numOfDay++;
            sumOfInches+=numOfInches;
        }

    }


    numOfTotalYards=sumOfInches/INCHES_PER_YARD;
    numOfRemainingInches=sumOfInches%INCHES_PER_YARD;
    numOfTotalFeets=numOfRemainingInches/INCHES_PER_FOOT;
    numOfRemainingInches=numOfRemainingInches%INCHES_PER_FOOT;



    cout<<"In "<<numOfDay-1<<" days, the snail traveled ";
    cout<<numOfTotalYards<<" yards, " ;
    cout<<numOfTotalFeets<<" feets and ";
    cout<<numOfRemainingInches<<" inches.";

    return 0;

}