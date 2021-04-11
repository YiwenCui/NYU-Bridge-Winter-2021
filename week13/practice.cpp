//Program to demonstrate the CDAccount structure type.
#include <iostream>
using namespace std;


// struct CDAccount {
// double balance;
// double interest_rate;
// int term;
// };

// void get_data(CDAccount& the_account);

// int main(){
//     CDAccount account;
//     get_data(account);

//     double rate_fraction, interest;
//     rate_fraction = account.interest_rate / 100.0;
//     interest = account.balance * rate_fraction * (account.term / 12.0);
//     account.balance = account.balance + interest;
//     cout.setf(ios::fixed);
//     cout.setf(ios::showpoint);
//     cout.precision(2);
//     cout << "When your CD matures in "
//         << account.term << " months,\n"
//         << "it will have a balance of $"
//         << account.balance << endl;
//     return 0;
// } 

// void get_data(CDAccount& the_account){
//     cout << "Enter account balance: $";
//     cin >> the_account.balance;
//     cout << "Enter account interest rate: ";
//     cin >> the_account.interest_rate;
//     cout << "Enter the number of months until maturity\n"
//         << "(must be 12 or fewer months): ";
//     cin >> the_account.term;
// }

class Thing{
    int val;
    int data;
public:
    Thing(int newVal, int newData){ val = newVal, data = newData; }
    int getVal()const {return val;}
    int getData()const {return data;}
    void setVal(int newVal){val = newVal;}
    void setData(int newData){data = newData;}
};

void myfunc(const Thing& t){
    cout<<t.getVal()<<endl;
    cout<<t.getData()<<endl;
    // t.setData(72);
    // t.setVal(25);
}

int main(){
    Thing t1(100,300);
    myfunc(t1);
    cout<<endl;
    myfunc(t1);
    return 0;
}


