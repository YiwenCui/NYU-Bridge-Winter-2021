#include<iostream>
using namespace std;

int analyzeDigits(int num, int& outSum);

int main(){
    int num, countDigs, sumDigs;
    sumDigs=0;

    cout<<"Please enter a positive integer:" <<endl;
    cin>>num;
    cout<<sumDigs<<endl;

    countDigs=analyzeDigits(num,sumDigs);
    
    cout<<sumDigs<<endl;
    cout<<num<<" has "<<countDigs<<" digits and their sum is "<<sumDigs<<endl;
    return 0;
}

int analyzeDigits(int num, int& outSum){
    int count, sum;
    int currDig;
    cout<<outSum<<endl;
    
    count=0;
    sum=0;
    while(num>0){
        currDig=num%10;
        count++;
        sum +=currDig;
        num=num/10;
    }
    outSum=sum;
    return count;
}