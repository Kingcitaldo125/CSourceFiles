#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

inline vector<int> bubbleSort(vector<int> mVec)
{
    vector<int> sorts;

    bool sorted = false;
    while (!sorted)
    {
        bool swap = false;

        for (int i = 0; i < mVec.size() - 1; ++i)
        {
            int cur, nxt;
            cur = mVec[i];     // 8
            nxt = mVec[i + 1]; // 4

            if (cur > nxt)
            {
                int holdr;
                holdr = nxt; // 4
                nxt = cur;   // 8
                cur = holdr; // 4

                mVec[i] = cur;
                mVec[i + 1] = nxt;

                swap = true;
                continue;
            }
        }

        if (!swap)
            sorted = true;
    }

    sorts = mVec;

    return sorts;
}

int main()
{
    vector<int> mVec;
    vector<int> mVecSorted;

    const int mEnd = 10;
    for (int i = 0; i < mEnd; ++i)
    {
        int mr = static_cast<int>(rand() % mEnd + 1);
        cout << "Item: " << mr << "\n";
        mVec.push_back(mr);
    }
    cout << "\n";

    mVecSorted = bubbleSort(mVec);

    vector<int>::iterator it;

    for (it = mVecSorted.begin(); it != mVecSorted.end(); ++it)
    {
        cout << "Item2: " << *it << "\n";
    }

    return 0;
}
