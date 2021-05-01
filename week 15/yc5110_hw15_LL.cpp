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
    int get_IdNumber() { return this->IdNumber; };
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

class Node
{
    friend class LinkList;

public:
    Node(Employee &data)
    {
        this->data = data;
        this->pre = nullptr;
        this->next = nullptr;
    };
    Employee get_data() { return this->data; };

private:
    Employee data;
    Node *pre;
    Node *next;
};

class LinkList
{
public:
    Node *get_head() { return this->head; };
    LinkList() { this->head = nullptr; };
    void addEmployee(Employee &randomEmployee);
    int size();
    Node* get_index(int index);

private:
    Node *head;
};

void LinkList::addEmployee(Employee &randomEmployee)
{
    Node *n = new Node(randomEmployee);
    if (head == nullptr)
    {
        head = n;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->pre = temp;
    }
}

int LinkList::size()
{
    int size = 0;
    if (head == nullptr)
    {
        return size;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp=temp->next;
            size++;
        }
        return size + 1;
    }
}

Node* LinkList::get_index(int index){
    Node* temp = this->head;
    if (index==0){
        return temp;
    }
    else{
        for(int i=0; i<index; i++){
            temp=temp->next;
        }
        return temp;
    }
}



class Hour
{
public:
    Hour(){};
    Hour(int IdNumber, int hour)
    {
        this->IdNumber = IdNumber;
        this->hour = hour;
    };
    int get_hour() { return this->hour; };
    int get_IdNumber() { return this->IdNumber; };
    void set_hour(int hour) { this->hour = hour; };

private:
    int IdNumber;
    int hour;
};

class Payroll
{
public:
    Payroll(){};
    Payroll(string name, double dollar)
    {
        this->name = name;
        this->dollar = dollar;
    };
    string get_name() { return this->name; };
    double get_dollar() { return this->dollar; };

private:
    string name;
    double dollar;
};

bool operator<(Payroll p1, Payroll p2)
{
    bool temp;
    if (p1.get_dollar() < p2.get_dollar())
    {
        temp = true;
    }
    else
    {
        temp = false;
    }

    return temp;
}

void readFile(ifstream &file, string fileName)
{
    //cout << "What's the file name?" << endl;
    // cin >> fileName;
    //fileName = "/Users/cuiyiwen/Desktop/NYU assignment/week 15/employeeList.txt";
    file.open(fileName);
    if (!file)
    {
        cout << "File failed to open" << endl;
        cout << "What's the file name?" << endl;
        // cin>>fileName;
        file.clear();
        file.open(fileName);
    }
}
int findIdx(vector<Hour> hourVec, int ID)
{
    int i = 0;
    while (ID != hourVec[i].get_IdNumber())
    {
        i++;
    }
    return i;
}

int main()
{
    ifstream file1;
    string fileName1 = "/Users/cuiyiwen/Desktop/NYU assignment/week 15/employeeList.txt";
    readFile(file1, fileName1);

    LinkList list;

    int randomID = -1;
    string randomName = "";
    double randomPayRate = -1;

    while (file1 >> randomID)
    {
        file1 >> randomPayRate;
        file1.ignore(9999, ' ');
        getline(file1, randomName);

        Employee random = Employee(randomID, randomName, randomPayRate);
        list.addEmployee(random);
    }

    ifstream file2;
    string fileName2 = "/Users/cuiyiwen/Desktop/NYU assignment/week 15/hourList.txt";
    readFile(file2, fileName2);
    vector<Hour> hourList;
    vector<int> IDs;

    int randomIDNumber, randomHour;

    while (file2 >> randomIDNumber)
    {
        file2 >> randomHour;
        if (find(IDs.begin(), IDs.end(), randomIDNumber) == IDs.end())
        {
            Hour random = Hour(randomIDNumber, randomHour);
            hourList.push_back(random);
            IDs.push_back(randomIDNumber);
        }
        else
        {
            int idx = findIdx(hourList, randomIDNumber);
            hourList[idx].set_hour(hourList[idx].get_hour() + randomHour);
        }
    }

    vector<Payroll> outputPayroll;
    string names = " ";
    double dollar = 0.0;

    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < hourList.size(); j++)
        {
            if (list.get_index(i)->get_data().get_IdNumber() == hourList[j].get_IdNumber())
            {
                names = list.get_index(i)->get_data().get_name();
                dollar = list.get_index(i)->get_data().get_payRate() * hourList[j].get_hour();
                Payroll random = Payroll(names, dollar);
                outputPayroll.push_back(random);
            }
        }
    }

    sort(outputPayroll.rbegin(), outputPayroll.rend());
    for (int i = 0; i < outputPayroll.size(); i++)
    {
        cout << outputPayroll[i].get_name() << " $" << outputPayroll[i].get_dollar() << endl;
    }

    return 0;
}