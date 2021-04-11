#include <iostream> 
#include <string>
using namespace std;

const double WEEKDAYS_8TO18_RATE = 0.40;
const double WEEKDAYS_18TO8_RATE = 0.25;
const double WEEKENDS_RATE = 0.15;
int main(){
    int hour, minute, lengthInMinutes;
    double cost;
    string weekOfDays;
    char temp;

    cout<<"Please enter the day of week you want to start the call (two charater string only, e.g. Mo, Tu, Su): ";
    cin>> weekOfDays;
    cout<<"Please enter the time you want to start the call (type in 24-hour notation): "<<endl;
    cin>>hour>>temp>>minute;
    cout<<"Please enter the length of the call in minutes (postive integer only): ";
    cin>>lengthInMinutes;

    if (weekOfDays == "Mo" || weekOfDays == "Tu" || weekOfDays == "We" || weekOfDays == "Th" || weekOfDays == "Fr"){
        if ((hour >= 8 && hour <= 17) && (minute >= 0 && minute <= 59)){
            cost = lengthInMinutes * WEEKDAYS_8TO18_RATE;
        }
        else if ((hour > 17 && hour <= 23) || (hour >= 0 && hour < 8) && (minute >= 0 && minute<=59)){
            cost = lengthInMinutes * WEEKDAYS_18TO8_RATE;
        }
    }
    else{
        cost = lengthInMinutes * WEEKENDS_RATE;
    }
    
    cout<<"Cost of the call: $"<< cost <<endl;
    

    return 0;
}
    

