#include <iostream>
using namespace std;

bool is2dupSequence(int seq[], int seqSize);

int main()
{
    int a[8] = {3, 3, 14, 14, 2, 3, 3, 3};
    cout << is2dupSequence(a, 8);
    return 0;
}

bool is2dupSequence(int seq[], int seqSize)
{
    if (seqSize == 2)
    {
        if (seq[0] == seq[1])
        {
            return true;
        }
    }
    else
    {
        bool a = is2dupSequence(seq, seqSize - 2);
        if (seq[seqSize - 1] == seq[seqSize - 2] && a == true)
        {
            return true;
        }
    }

    return false;
}
