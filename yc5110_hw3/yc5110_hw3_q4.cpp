#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;
int main(){
    double realNumber;
    int selection;
    int floorResult, ceilingResult, roundResult;

    cout<<"Please enter a real number: "<<endl;
    cin>>realNumber;

    cout<<"Choose your rounding method"<<endl;
    cout<<"1. Floor round"<<endl;
    cout<<"2. Ceiling round"<<endl;
    cout<<"3. Round to the nearest number"<<endl;
    cin>> selection;
    
    switch(selection){
        case 1:
            if (realNumber>0 || realNumber == int(realNumber)){
                cout<<int(realNumber)<<endl;
            }
            else{
                cout<<int(realNumber)-1<<endl;
            }
            break;
        case 2:
            if (realNumber<0 || realNumber == int(realNumber)){
                cout<<int(realNumber)<<endl;
            }
            else{
                cout<<int(realNumber)+1<<endl;
            }
            break;
        case 3:
            if (realNumber >0){
                if (realNumber - int(realNumber) >= 0.5){
                    cout<<int(realNumber)+1<<endl;
                }
                else{
                    cout<<int(realNumber)<<endl;
                }
            }
            else{  
                if (realNumber - int(realNumber) <= -0.5){
                    cout<<int(realNumber)-1<<endl; 
                }
                else{
                    cout<<int(realNumber)<<endl;
                }
                                             
            }
            break;        
    }
    return 0;   
}
