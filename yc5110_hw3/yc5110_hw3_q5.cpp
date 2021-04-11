#include <iostream>
using namespace std;

const double KG_PER_LB = 0.453592;
const double M_PER_INCH = 0.0254;

int main(){
    double weightInLbs, heightInM;
    double weightInKgs, heightInInches;
    double BMI;

    cout<<"Please enter weight(in pounds): ";
    cin>> weightInLbs;
    cout<<"Please enter height(in inches): ";
    cin>> heightInInches;

    weightInKgs = weightInLbs * KG_PER_LB;
    heightInM = heightInInches * M_PER_INCH;
    BMI = weightInKgs/(heightInM*heightInM);

    if(BMI<18.5)
        cout<<"The weight status is: "<<"Underweight"<<endl;
    else if (BMI>=18.5 && BMI<25)
        cout<<"The weight status is: "<<"Normal"<<endl;
    else if (BMI>=25 && BMI<30)
        cout<<"The weight status is: "<<"Overweight"<<endl;
    else 
        cout<<"The weight status is: "<<"Obese";
    
    
    return 0;

}

