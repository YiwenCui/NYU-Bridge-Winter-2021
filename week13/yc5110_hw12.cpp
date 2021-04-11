#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Money
{
public:
    friend Money operator+(const Money &amount1, const Money &amount2);
    friend Money operator-(const Money &amount1, const Money &amount2);
    friend Money operator-(const Money &amount);
    friend bool operator==(const Money &amount1, const Money &amount2);
    friend bool operator<(const Money &amount1, const Money &amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money();

    double get_value() const { return all_cents; };
    friend istream &operator>>(istream &ins, Money &amount);
    friend ostream &operator<<(ostream &outs, const Money &amount);

private:
    long all_cents;
};

class Check
{
private:
    string numOfCheck;
    bool isCashed;
    Money amountOfCheck;

public:
    Check(string numOfCheck, Money amountOfCheck, bool isCashed)
    {
        this->numOfCheck = numOfCheck;
        this->amountOfCheck = amountOfCheck;
        this->isCashed = isCashed;
    };
    string get_numOfCheck() { return this->numOfCheck; };
    long get_amountOfCheck() { return this->amountOfCheck.get_value(); };
    Money get_amountOfCheck1() { return this->amountOfCheck; }
    bool get_isCashed() { return this->isCashed; };
    friend bool operator<(const Check &check1, const Check &check2);
};

int main()
{
    vector<Check> allchecks;
    vector<Money> alldeposits;
    Money oldBalanceBankAndCustomer;
    Money newBalanceBank;
    Money newBalanceCustomer;
    bool isCashed = 0;
    char ifContinue = 'Y';
    Money sumOfDeposits;
    Money amountOfCashedChecks;
    Money amountOfAllChecks;
    vector<Check> allCashedChecks;
    vector<Check> allNonCashedChecks;

    cout << "What is your old balance? (the format should be $dollars.cents)" << endl;
    cin >> oldBalanceBankAndCustomer;
    while (ifContinue != 'N')
    {
        ifContinue = 'N';
        string checkID;
        Money amountOfCheck;
        bool isCashed;

        cout << "Please enter the number of check, the amount of the check and whetehr or not it has been cashed. (1 or 0, separte your answers by space)" << endl;
        cin >> checkID >> amountOfCheck >> isCashed;
        Check randomCheck = Check(checkID, amountOfCheck, isCashed);
        allchecks.push_back(randomCheck);
        if (randomCheck.get_isCashed() == 0)
        {
            allNonCashedChecks.push_back(randomCheck);
        }
        else
        {
            allCashedChecks.push_back(randomCheck);
        }

        cout << "Do you have another check to input? ('Y' for Yes and 'N' for No)" << endl;
        cin >> ifContinue;
    }

    sort(allCashedChecks.begin(), allCashedChecks.end());
    sort(allNonCashedChecks.begin(),allNonCashedChecks.end());


    // for (int i = 0; i < allchecks.size(); i++)
    // {
    //     cout << allchecks[i].get_numOfCheck() << '\t' << allchecks[i].get_amountOfCheck() << '\t' << allchecks[i].get_isCashed() << endl;
    // }

    ifContinue = 'Y';
    while (ifContinue != 'N')
    {
        ifContinue = 'N';
        Money randomDeposit;

        cout << "Please enter deposit (the format should be $dollars.cents)." << endl;
        cin >> randomDeposit;
        alldeposits.push_back(randomDeposit);
        cout << "Do you have another deposit to input? ('Y' for Yes and 'N' for No)" << endl;
        cin >> ifContinue;
    }
    // for (int i = 0; i < alldeposits.size(); i++)
    // {
    //     cout << alldeposits[i].get_value() << endl;
    // }

    for (int i = 0; i < alldeposits.size(); i++)
    {
        sumOfDeposits = sumOfDeposits + alldeposits[i];
    }

    for (int i = 0; i < allchecks.size(); i++)
    {
        if (allchecks[i].get_isCashed() == 1)
        {
            amountOfCashedChecks = amountOfCashedChecks + allchecks[i].get_amountOfCheck1();
        }
    }

    for (int i = 0; i < allchecks.size(); i++)
    {
        amountOfAllChecks = amountOfAllChecks + allchecks[i].get_amountOfCheck1();
    }

    cout << "Your total cashed check amount is: " << amountOfCashedChecks << endl;
    cout << "Your total deposits is: " << sumOfDeposits << endl;
    newBalanceBank = oldBalanceBankAndCustomer - amountOfCashedChecks + sumOfDeposits;
    newBalanceCustomer = oldBalanceBankAndCustomer - amountOfAllChecks + sumOfDeposits;
    cout << "Your actual new balance is: " << newBalanceCustomer << endl;
    cout << "The difference between actual balance and the blance from bank is: " << newBalanceBank - newBalanceCustomer << endl;

    cout << "The list of cashed checks:" << endl;
    for (int i=0; i<allCashedChecks.size(); i++){
        cout<<"["<<allCashedChecks[i].get_numOfCheck()<<","<<allCashedChecks[i].get_amountOfCheck1()<<"]"<<endl;
        
    }

    cout << "The list of uncahsed checks:" << endl;
    for (int i=0; i<allNonCashedChecks.size(); i++){
        cout<<"["<<allNonCashedChecks[i].get_numOfCheck()<<","<<allNonCashedChecks[i].get_amountOfCheck1()<<"]"<<endl;
        
    }
   
    // for (int i = 0; i < allCashedChecks.size(); i++)
    // {
    //     cout << allCashedChecks[i].get_numOfCheck() << '\t' << allCashedChecks[i].get_amountOfCheck1() << endl;
    // }

    
    // for (int i = 0; i < allNonCashedChecks.size(); i++)
    // {

    //     cout << allNonCashedChecks[i].get_numOfCheck() << '\t' << allNonCashedChecks[i].get_amountOfCheck1() << endl;
    // }

    return 0;
}

Money operator+(const Money &amount1, const Money &amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

Money operator-(const Money &amount1, const Money &amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator-(const Money &amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator==(const Money &amount1, const Money &amount2)
{
    bool temp;
    if (amount1 == amount2)
    {
        temp = true;
    }
    else
    {
        temp = false;
    }

    return temp;
}

bool operator<(const Money &amount1, const Money &amount2)
{
    bool temp;
    if (amount1 < amount2)
    {
        temp = true;
    }
    else
    {
        temp = false;
    }

    return temp;
}

bool operator<(const Check &check1, const Check &check2)
{
    bool temp;
    if (check1.numOfCheck < check2.numOfCheck)
    {
        temp = true;
    }
    else
    {
        temp = false;
    }
    return temp;
}

int digit_to_int(char a)
{
    return int(a) - '0';
}
Money::Money(long dollars, int cents)
{
    all_cents = dollars * 100 + cents;
};
Money::Money(long dollars)
{
    all_cents = dollars * 100;
};
Money::Money() : all_cents(0){};

istream &operator>>(istream &ins, Money &amount)
{
    char one_char, decimal_point, digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative; //set to true if input is negative.

    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
    {
        // if the input is legal, then one_char == '$'
        negative = false;
    }

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2))
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;

    if (negative)
        amount.all_cents = -amount.all_cents;

    return ins;
}
ostream &operator<<(ostream &outs, const Money &amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0)
        outs << "- $" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';

    outs << cents;

    return outs;
}
