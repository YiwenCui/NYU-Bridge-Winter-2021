#include <iostream>
#include <string>
using namespace std;

int main()
{
    string firstName, middleName, lastName;
    cout << "Please enter your name in following format: First name, Middle name or Initial, Last name."<<endl;
    cin >> firstName >> middleName >> lastName;

    cout << lastName << ", " << firstName << " " << middleName[0] << ".";

    return 0;
}