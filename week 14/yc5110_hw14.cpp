#include <iostream>
#include <vector>

using namespace std;

void findMinandMax(vector<int> vec, int &minLeft, int &maxLeft, int &minRight, int &maxRight, int &min, int &max);
void divide(vector<int> vec, int &min, int &max);
void printvec(vector<int> vec);

int main()
{
    int min, max;
    int minLeft, maxLeft, minRight, maxRight;
    vector<int> vec1;
    vec1.push_back(2);
    vec1.push_back(1);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(7);

    divide(vec1, min, max);
    
    vector<int>vecMinAndMax;
    vecMinAndMax.push_back(min);
    vecMinAndMax.push_back(max);

    printvec(vecMinAndMax);

    return 0;
}

void findMinandMax(vector<int> vec, int &minLeft, int &maxLeft, int &minRight, int &maxRight, int &min, int &max)
{

    if (minLeft <= minRight)
    {
        min = minLeft;
    }
    else
    {
        min = minRight;
    }

    if (maxLeft >= maxRight)
    {
        max = maxLeft;
    }
    else
    {
        max = maxRight;
    }
}

void divide(vector<int> vec, int &min, int &max)
{
    int size = vec.size();
    vector<int> vecLeftHalf;
    vector<int> vecRightHalf;
    int mid = vec.size() / 2 - 1;

    if (vec.size() == 1)
    {
        min = vec[0];
        max = vec[0];
        return;
    }

    for (int i = 0; i <= mid; i++)
    {
        vecLeftHalf.push_back(vec[i]);
    }

    for (int i = mid + 1; i < size; i++)
    {
        vecRightHalf.push_back(vec[i]);
    }

    divide(vecLeftHalf, min, max);
    int minLeft = min, maxLeft = max;

    divide(vecRightHalf, min, max);
    int minRight = min, maxRight = max;

    findMinandMax(vec, minLeft, maxLeft, minRight, maxRight, min, max);
}

void printvec(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}