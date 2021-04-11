#include<iostream>
using namespace std;

const float CLUB_CARD_MEMBER_DISCOUNT = 0.9;
const float LOWER_PRICE_ITEM_DISCOUNT = 0.5;
const float TAX_RATE_CONVERSION=0.01;

int main(){
    float priceOfFirstItem, priceOfSecondItem;
    float totalBasePrice, totalPriceAfterDiscount, totalPriceAfterCardMemeberDiscount;
    float taxRate, taxRatePercentage;
    char ifHaveClubCard;
    float totalAfterTaxPrice;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout<<"Enter price of first item: ";
    cin>>priceOfFirstItem;
    cout<<"Enter price of second item: ";
    cin>>priceOfSecondItem;
    cout<<"Does customer have a club card?(Y/N): ";
    cin>>ifHaveClubCard;  
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>taxRate;
    cout<<"Base price: "<< priceOfFirstItem + priceOfSecondItem<<endl;

    if (priceOfSecondItem <= priceOfFirstItem)
        priceOfSecondItem *= LOWER_PRICE_ITEM_DISCOUNT;
    else
        priceOfFirstItem *= LOWER_PRICE_ITEM_DISCOUNT;
    
    totalPriceAfterDiscount = priceOfFirstItem + priceOfSecondItem;

    if (ifHaveClubCard == 'y' || ifHaveClubCard == 'Y' )
        totalPriceAfterCardMemeberDiscount = totalPriceAfterDiscount * CLUB_CARD_MEMBER_DISCOUNT;
    else if(ifHaveClubCard =='n' || ifHaveClubCard == 'N')
        totalPriceAfterCardMemeberDiscount = totalPriceAfterDiscount;

    cout<<"Price after discount: " << totalPriceAfterCardMemeberDiscount<<endl;
       
    taxRatePercentage = taxRate * TAX_RATE_CONVERSION;
    totalAfterTaxPrice = totalPriceAfterCardMemeberDiscount * (1 + taxRatePercentage);
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    cout<<"Total price: "<< totalAfterTaxPrice<<endl;

    return 0;
}
