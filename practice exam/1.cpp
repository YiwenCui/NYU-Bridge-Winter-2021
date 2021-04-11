#include <iostream>

int main()
{
    int n;

    std :: cout <<"Enter n :" ;
    std :: cin >> n;

    int initialSpaces = n-1;
    int stars = n-initialSpaces;

    for(int i = 1; i <= 2 * n -1; i++)
    {
        
        for(int j = 1; j <= initialSpaces; j++)
        {
            std:: cout << " "  ;
        }
        
        for(int j = 1; j <= stars; j++)
        {
            std :: cout << "* ";
        }
        std :: cout << std::endl;

        if(i < n)
        {
            initialSpaces --;
            stars++;
        }
        else
        {
            initialSpaces++;
            stars --;
        }
    }

    return 0;

}