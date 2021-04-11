#include<iostream>
#include<string>
using namespace std;

int main(){
    string name;
    int graduationYear, currentYear, yearDifference;

    cout<<"Please enter your name: ";
    cin>>name;
    cout<<"Please enter your graduation year: ";
    cin>>graduationYear;
    cout<<"Please enter current year: ";
    cin>>currentYear;

    yearDifference = graduationYear - currentYear;

    if (yearDifference <=0)
        cout<< name<<", you are Graduated";

    else if (yearDifference > 0 && yearDifference <= 4)
        switch(yearDifference){
            case 4:
                cout<< name<<", you are a Freshman"<<endl;
                break;
            case 3:
                cout<< name<<", you are a Sophomore"<<endl;
                break;
            case 2:
                cout<< name<<", you are a Junior"<<endl;
                break;
            case 1:
                cout<< name<<", you are a Senior"<<endl;
                break;
        }
    
    else 
        cout<< name<<", you are not in college yet"<<endl;
    
    return 0;
}

        

           
      