#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int &outCountDivs, int &outSumDivs);
bool isPerfect(int num);

int main()
{
    int num, i,a, countDivs, sumDivs;
    cout << "Please enter a positive integer (greater or equal to 2)";
    cin >> num;
    cout<<"All the perfect numbers between 2 and num: "<<endl;
    for (i = 2; i <= num; i++)
    {
        if (isPerfect(i) == 1)
        {
            cout << i;
            cout<<'\t';
        }
    }
    cout<<endl<<"All pairs of amicable numbers that are between 2 and num:"<<endl;
    for (i=2; i<= num; i++){
        analyzeDividors(i, countDivs, sumDivs);
        a=sumDivs;
        analyzeDividors(a, countDivs, sumDivs);
        if (i==sumDivs && a< sumDivs){
            cout<< a <<'\t'<< sumDivs<<endl;
        }
    }


    return 0;
}
void analyzeDividors(int num, int &outCountDivs, int &outSumDivs)
{
    int i, j, sum = 0, count = 0;
    int numsquareRoot = pow(num, 1.0 / 2);

    for (i = 1; i <= numsquareRoot; i++)
    {
        if (num % i == 0)
        {
            sum += i;
            count++;
        }
    }

    for (j = numsquareRoot; j >= 1; j--)
    {
        if (num % j == 0 && ((num / j) != i - 1) && ((num / j) != num))
        {
            sum += num / j;
            count++;
        }
    }
    outCountDivs = count;
    outSumDivs = sum;
}

bool isPerfect(int num)
{
    int countDivs, sumDivs;
    analyzeDividors(num, countDivs, sumDivs);
    if (sumDivs == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}
