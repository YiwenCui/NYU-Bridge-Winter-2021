#include<iostream>
using namespace std;

const int MINUTES_PER_DAY = 1440;
const int HOURS_PER_DAY = 24;
const int MINUTES_PER_HOUR = 60;
int main(){
    int numberOfDaysJohnWorked, numberOfHoursJohnWorked, numberOfMinutesJohnWorked;
    int numberOfDaysBillWorked, numberOfHoursBillWorked, numberOfMinutesBillWorked;
    int totalMinutesJohnWorked, totalMinutesBillworked, totalMinutesBothWorked;
    int daysBothWorkTogether, hoursBothWorkTogether;
    int remainingMinutesAfterFullDays, remainingMinutesAfterFullHours;

    cout<< "Please enter the number of days John has worked: ";
    cin>> numberOfDaysJohnWorked;
    cout<< "Please enter the number of hours John has worked: ";
    cin>> numberOfHoursJohnWorked;
    cout<< "Please enter the number of minutes John has worked: ";
    cin>> numberOfMinutesJohnWorked;

    cout<< "Please enter the number of days Bill has worked: ";
    cin>> numberOfDaysBillWorked;
    cout<< "Please enter the number of hours Bill has worked: ";
    cin>> numberOfHoursBillWorked;
    cout<< "Please enter the number of minutes Bill has worked: ";
    cin>> numberOfMinutesBillWorked;

    totalMinutesJohnWorked = numberOfDaysJohnWorked * MINUTES_PER_DAY + numberOfHoursJohnWorked * MINUTES_PER_HOUR + numberOfMinutesJohnWorked;
    totalMinutesBillworked = numberOfDaysBillWorked * MINUTES_PER_DAY + numberOfHoursBillWorked * MINUTES_PER_HOUR + numberOfMinutesBillWorked;
    totalMinutesBothWorked = totalMinutesJohnWorked + totalMinutesBillworked;

    daysBothWorkTogether = totalMinutesBothWorked / MINUTES_PER_DAY;
    remainingMinutesAfterFullDays = totalMinutesBothWorked % MINUTES_PER_DAY;
    hoursBothWorkTogether = remainingMinutesAfterFullDays / MINUTES_PER_HOUR;
    remainingMinutesAfterFullHours = remainingMinutesAfterFullDays % MINUTES_PER_HOUR;

    cout<< "The total time both of them worked together is: " << daysBothWorkTogether<<" days, "<< hoursBothWorkTogether<< " hours and " << remainingMinutesAfterFullHours<< " minutes.";

    return 0;
}
