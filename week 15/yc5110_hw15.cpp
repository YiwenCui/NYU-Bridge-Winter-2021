#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Employee
{
public:
    Employee(){};
    Employee(int IdNumber, string name, double payRate);
    int& get_IdNumber() { return this->IdNumber; };
    string get_name() { return this->name; };
    double get_payRate() { return this->payRate; };

private:
    int IdNumber;
    string name;
    double payRate;
};

Employee::Employee(int IdNumber, string name, double payRate)
{
    this->IdNumber = IdNumber;
    this->name = name;
    this->payRate = payRate;
}

void readFile(ifstream &file)
{
    string fileName;
    cout << "What's the file name?" << endl;
    // cin >> fileName;
    fileName = "";
    file.open(fileName);
    if (!file)
    {
        cout << "not read\n";
        cout<<"File failed to open"<<endl;
        cout<<"What's the file name?"<<endl;
        // cin>>fileName;
        fileName = "employeeList.txt";
        file.clear();
        file.open(fileName);
    }
    cout << "read\n";
}

int main()
{
    ifstream file;
    readFile(file);
    vector<Employee> list;
    Employee random;
    int randomID = random.get_IdNumber();
    string randomName = random.get_name();
    double randomPayRate = random.get_payRate();

    // file >> randomID >> randomPayRate;
    // file >> randomID;
    // file >> randomPayRate;
    // cout << randomID << "|" << randomPayRate;
    while(file >> randomID){
        file >> randomPayRate;
        file.ignore(9999, '\t');
        getline(file, randomName);
        list.push_back(random);
    }
    // for (int i =0; i<list.size(); i++){
    //     if (list[i].get_payRate()<=6){
    //         cout<<list[i].get_IdNumber();
    //     }
    // }

    return 0;
}