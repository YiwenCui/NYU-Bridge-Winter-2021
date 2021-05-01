#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class LList;

template <class T>
class LListItr;

template <class T>
class LListNode {
	T data;
	LListNode<T>* next;
	LListNode<T>* prev;
public:
	LListNode(const T& newdata = T(), LListNode<T>* newnext = nullptr, LListNode<T>* newprev = nullptr) :data(newdata), next(newnext), prev(newprev) {}
	friend class LList<T>;
	friend class LListItr<T>;
};
class EmptyListError {};

template <class S>
class LListItr {
		LListNode<S>* ptr;
	public:
		LListItr(LListNode<S>* newptr=nullptr) :ptr(newptr) {}
		S& operator*() { return ptr->data; }
		S operator*() const { return ptr->data; }
		LListItr operator++(int);
		LListItr& operator++();
		LListItr operator--(int);
		LListItr& operator--();
		bool operator==(const LListItr<S>& rhs) const { return ptr == rhs.ptr; }
		bool operator!=(const LListItr<S>& rhs) const { return ptr != rhs.ptr; }
		friend class LList<S>;
};

template <class T>
class LList {
	LListNode<T>* head;
	LListNode<T>* tail;
	int numElements;
public:
	
	LListItr<T> begin() { return head->next; }
	LListItr<T> end() { return tail; }
	bool isEmpty() const { return numElements == 0; }
	LList();
	virtual ~LList();
	void push_front(const T& newdata);
	void push_back(const T& newdata) { insertAfter(newdata, tail->prev); }
	int size() const { return numElements; }
	void clear();
	LList(const LList<T>& rhs);
	LList& operator=(const LList& rhs);
	T pop_front() { if (!isEmpty()) return removeNode(head->next); else throw EmptyListError(); }
	T pop_back() { if (!isEmpty()) return removeNode(tail->prev); else throw EmptyListError(); }
	
	void insertAfter(const T& newdata, LListItr<T> itr);
	T removeNode(LListItr<T> itr);
};
template <class T>
LListItr<T> LListItr<T>::operator--(int) {
	LListItr<T> temp = *this;
	if (ptr->prev != nullptr)
		ptr = ptr->prev;
	return temp;
}
template <class T>
LListItr<T>& LListItr<T>::operator--() {
	if (ptr->prev != nullptr)
		ptr = ptr->prev;
	return *this;
}

template <class T>
LListItr<T> LListItr<T>::operator++(int) {
	LListItr<T> temp = *this;
	if (ptr->next != nullptr)
		ptr = ptr->next;
	return temp;
}
template <class T>
LListItr<T>& LListItr<T>::operator++() {
	if (ptr->next != nullptr)
		ptr = ptr->next;
	return *this;
}
template <class T>
T LList<T>::removeNode(LListItr<T> itr) {
	LListNode<T>* toDelete = itr.ptr;
	T retval = toDelete->data;
	toDelete->prev->next = toDelete->next;
	toDelete->next->prev = toDelete->prev;

	delete toDelete;
	numElements--;
	return retval;
}

template <class T>
void LList<T>::insertAfter(const T& newdata, LListItr<T> itr) {
	LListNode<T>* temp = itr.ptr;
	numElements++;
	temp->next = new LListNode<T>(newdata, temp->next, temp);
	temp->next->next->prev = temp->next;


	/*LListNode<T>* newnode = new LListNode<T>;
	newnode->prev = temp;
	newnode->next = temp->next;
	temp->next = newnode;
	newnode->next->prev = newnode;
	*/

}
template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
	if (this == &rhs)
		return *this;
	clear();
	
	for(LListNode<T>* temp = rhs.head->next; temp != rhs.tail; temp = temp->next)
		push_back(temp->data);
	return *this;
}
template <class T>
LList<T>::LList(const LList<T>& rhs) {
	numElements = 0;
	head = new LListNode<T>(T(), new LListNode<T>); //create two dummy nodes.
	tail = head->next;
	tail->prev = head;
	*this = rhs;
}
template <class T>
void LList<T>::clear() {
	while (!isEmpty())
		removeNode(head->next);
}
template <class T>
void LList<T>::push_front(const T& newdata) {
	insertAfter(newdata, head);
}
template <class T>
LList<T>::~LList() {
	clear();
	delete head;
	delete tail;
}
template <class T>
LList<T>::LList() {
	numElements = 0;
	head = new LListNode<T>(T(), new LListNode<T>); //create two dummy nodes.
	tail = head->next;
	tail->prev = head;
}

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
    vector<Employee> list;

    int randomID = -1;
    string randomName = "";
    double randomPayRate = -1;

    while (file1 >> randomID)
    {
        file1 >> randomPayRate;
        file1.ignore(9999, ' ');
        getline(file1, randomName);

        Employee random = Employee(randomID, randomName, randomPayRate);
        list.push_back(random);
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
            if (list[i].get_IdNumber() == hourList[j].get_IdNumber())
            {
                names = list[i].get_name();
                dollar = list[i].get_payRate() * hourList[j].get_hour();
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