#include <iostream>
using namespace std;

const int DAYS_OF_WEEK = 7;
const int DAYS_OF_JANUARY = 31, DAYS_OF_MARCH = 31, DAYS_OF_MAY = 31, DAYS_OF_JULY = 31, DAYS_OF_AUGUST = 31, DAYS_OF_OCTOBER = 31, DAYS_OF_DECEMBER = 31;
const int DAYS_OF_APRIL = 30, DAYS_OF_JUNE = 30, DAYS_OF_SEPTEMBER = 30, DAYS_OF_NOVEMBER = 30;
int printMonthCalender(int numOfDays, int startingDay);
bool leapYear(int year);
void printYearCalender(int year, int startingDay);

int main()
{
    int year, startingDay;
    cout << "Please choose a year and startingDay, seperate by space" << endl;
    cin >> year >> startingDay;
    printYearCalender(year, startingDay);
    return 0;
}

int printMonthCalender(int numOfDays, int startingDay)
{
    int lineCount, columnCount;
    int counter = 1;
    int maxlineCount;

    if ((startingDay + numOfDays - 1) % DAYS_OF_WEEK == 0)
    {
        maxlineCount = (startingDay + numOfDays - 1) / DAYS_OF_WEEK;
    }
    else
    {
        maxlineCount = (startingDay + numOfDays - 1) / DAYS_OF_WEEK + 1;
    }

    cout << "Mon" << '\t' << "Tue" << '\t' << "Wed" << '\t' << "Thr" << '\t' << "Fri" << '\t' << "Sat" << '\t' << "Sun" << endl;

    for (lineCount = 1; lineCount <= maxlineCount; lineCount++)
    {

        for (columnCount = 1; columnCount <= 7; columnCount++)
        {
            if (columnCount < startingDay && lineCount == 1)
            {
                cout << "  " << '\t';
            }
            else
            {
                cout << counter;
                if (counter <= 9)
                {
                    cout << " " << '\t';
                }
                else
                {
                    cout << '\t';
                }
                counter++;
                if (counter == numOfDays + 1)
                {
                    break;
                }
            }
        }
        cout << endl;
    }
    return columnCount;
}

bool leapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
    {
        return true;
    }
    else if (year % 400 == 0){
        return true;
    }
    else
    {
        return false;
    }
}

void printYearCalender(int year, int startingDay)
{
    int daysOfFebruary;
    int febStartingDay, marStartingDay, aprStartingDay, mayStartingDay, juneStartingDay, julyStartingDay;
    int augStartingDay, sepStartingDay, octStartingDay, novStartingDay, decStartingDay;

    if (leapYear(year) == true)
    {
        daysOfFebruary = 29;
    }
    else
    {
        daysOfFebruary = 28;
    }
    // Jan
    cout << "January " << year << endl;
    febStartingDay = printMonthCalender(DAYS_OF_JANUARY, startingDay) + 1;
    cout<<endl;

    // Feb
    cout << "February " << year << endl;
    if (febStartingDay==8){
        febStartingDay=1;
    }
    marStartingDay = printMonthCalender(daysOfFebruary, febStartingDay) + 1;
    cout<<endl;

    // Mar
    cout << "March " << year << endl;
    if (marStartingDay==8){
        marStartingDay=1;
    }
    aprStartingDay = printMonthCalender(DAYS_OF_MARCH, marStartingDay) + 1;
    cout<<endl;

    // Apr
    cout << "April " << year << endl;
    if (aprStartingDay==8){
        aprStartingDay=1;
    }
    mayStartingDay = printMonthCalender(DAYS_OF_APRIL, aprStartingDay) + 1;
    cout<<endl;

    // May
    cout << "May " << year << endl;
    if (mayStartingDay==8){
        mayStartingDay=1;
    }
    juneStartingDay = printMonthCalender(DAYS_OF_MAY, mayStartingDay) + 1;
    cout<<endl;

    // June
    cout << "June " << year << endl;
    if (juneStartingDay==8){
        juneStartingDay=1;
    }
    julyStartingDay = printMonthCalender(DAYS_OF_JUNE, juneStartingDay) + 1;
    cout<<endl;

    // July
    cout << "July " << year << endl;
    if (julyStartingDay==8){
        julyStartingDay=1;
    }
    augStartingDay = printMonthCalender(DAYS_OF_JULY, julyStartingDay) + 1;
    cout<<endl;

    // August
    cout << "August " << year << endl;
    if (augStartingDay==8){
        augStartingDay=1;
    }
    sepStartingDay = printMonthCalender(DAYS_OF_AUGUST, augStartingDay) + 1;
    cout<<endl;

    // Sepetember
    cout << "Sepetember " << year << endl;
    if (sepStartingDay==8){
        sepStartingDay=1;
    }
    octStartingDay = printMonthCalender(DAYS_OF_SEPTEMBER, sepStartingDay) + 1;
    cout<<endl;

    // October
    cout << "October " << year << endl;
    if (octStartingDay==8){
        octStartingDay=1;
    }
    novStartingDay = printMonthCalender(DAYS_OF_OCTOBER, octStartingDay) + 1;
    cout<<endl;

    // November
    cout << "November " << year << endl;
    if (novStartingDay==8){
        novStartingDay=1;
    }
    decStartingDay = printMonthCalender(DAYS_OF_NOVEMBER, novStartingDay) + 1;
    cout<<endl;

    // December
    cout << "December " << year << endl;
    if (decStartingDay==8){
        decStartingDay=1;
    }
    printMonthCalender(DAYS_OF_DECEMBER, decStartingDay);
    cout<<endl;
}
