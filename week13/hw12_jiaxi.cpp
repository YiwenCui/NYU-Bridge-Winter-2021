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
    double amountOfCheck;
    bool isCashed;
    Money temp;

public:
    Check(string numOfCheck, Money t, bool isCashed)
    {
        this->numOfCheck = numOfCheck;
        // this->amountOfCheck = amountOfCheck;1
        this->isCashed = isCashed;
        this->temp = t;
    };
    string get_numOfCheck() { return this->numOfCheck; };
    long get_temp() { return this->temp.get_value(); };
    bool get_isCashed() { return this->isCashed; };
};

int main()
{
    // vector<Check> allchecks;
    // bool isCashed = 0;
    // int cashCount = 0;
    char ifContinue = 'Y';
    // while (ifContinue != 'N')
    // {
    //     ifContinue = 'N';
    //     string checkID;
    //     double amoutnOfCheck;
    //     Money temp;
    //     bool isCashed;
    //     // cout << endl << temp.get_value() << endl;

    //     cout << "Please enter the number of check, the amount of the check and whetehr or not it has been cashed. (1 or 0, separte your answers by space)" << endl;
    //     cin >> checkID >> temp >> isCashed;

    //     Check randomCheck = Check(checkID, temp, isCashed);
    //     allchecks.push_back(randomCheck);
    //     cashCount++;
    //     cout << "Do you have another check to input? ('Y' for Yes and 'N' for No)" << endl;
    //     cin >> ifContinue;
    // }
    // for (int i = 0; i < cashCount; i++)
    // {
    //     cout << allchecks[i].get_numOfCheck() << '\t' << allchecks[i].get_temp() << '\t' << allchecks[i].get_isCashed() << endl;
    // }

    vector<Money> allDs;
    cout << "add dposiute" << endl;
    ifContinue = 'Y';
    while (ifContinue != 'N')
    {
        Money d;
        cin >> d;
        allDs.push_back(d);
        cout << "Do you have another check to input? ('Y' for Yes and 'N' for No)" << endl;
        cin >> ifContinue;
    }
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

    cents = 100;
    amount.all_cents = dollars * 100 + cents;

    if (negative)
        amount.all_cents = -amount.all_cents;

    return ins;
}
// ostream &operator<<(ostream &outs, const Money &amount)
// {
//     long positive_cents, dollars, cents;
//     positive_cents = labs(amount.all_cents);
//     dollars = positive_cents / 100;
//     cents = positive_cents % 100;

//     if (amount.all_cents < 0)
//         outs << "- $" << dollars << '.';
//     else
//         outs << "$" << dollars << '.';

//     if (cents < 10)
//         outs << '0';

//     outs << cents;

//     return outs;
// }