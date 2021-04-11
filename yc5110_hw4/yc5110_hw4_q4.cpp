#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //a)
    int num, sequenceLength;
    int x;
    double geometricMean;
    int numProduct;

    cout << "Please enter the length of the sequence: ";
    cin >> sequenceLength;

    numProduct = 1;
    x = 0;

    for (x = 0; x < sequenceLength; x++)
    {
        cin >> num;
        numProduct *= num;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    geometricMean = pow(numProduct, 1 / double(sequenceLength));
    cout << "The geometric mean is: " << geometricMean << endl;
    cout << endl;

    //b)
    cout << "Please enter your sequence: " << endl;

    numProduct = 1;
    x = 0;

    for (x = 0;; x++)
    {
        cin >> num;
        if (num == -1)
        {
            break;
        }
        numProduct *= num;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    geometricMean = pow(numProduct, 1 / double(x));
    cout << "The geometric mean is: " << geometricMean;

    return 0;
}