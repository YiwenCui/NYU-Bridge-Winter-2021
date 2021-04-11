#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double a, b, c;
    double delta, solution1, solution2;

    cout<<"Please enter value of a: ";
    cin>>a;
    cout<<"Please enter value of b: ";
    cin>>b;
    cout<<"Please enter value of c: ";
    cin>>c;

    delta = b*b - 4*a*c;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    if (a==0){
        if(b==0 && c==0){
            cout<<"This equation has infinite number of solutions";
        }
        else if (b==0 && c!=0){
            cout<<"This equation has no solution";
        }
        else{
            solution1= -c/b;
            cout<<"This equation has one real solution"<<" x= "<<solution1;
        }
    }
    else
        if (delta<0){
            cout<<"This equation has no real solution";
        }
        else if (delta == 0){
            solution1 = -b/(2*a);
            cout<<"This equation has one real solution"<<" x= "<<solution1<<endl;
        }
        else if (delta > 0){
            solution1 = (-b-sqrt(delta))/(2*a);
            solution2 = (-b+sqrt(delta))/(2*a);
            cout<<"This equation has two real solutions"<<" x= "<<solution1<<" and x = "<<solution2;
        }
    return 0 ;

}