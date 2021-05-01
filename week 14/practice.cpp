#include <iostream>
#include <vector>

using namespace std;

void findMinandMax(vector<int> vec);
void divide(vector<int> vec);
void printvec(vector<int> vec);

int main()
{
    int min, max;
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);

    cout<<vec1[-1];
    return 0;
}