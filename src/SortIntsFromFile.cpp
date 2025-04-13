#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::vector;

inline void readFile(vector<int> &mVec)
{
    ifstream f("inFile.txt", std::ios::in);

    int itm;

    while (f >> itm)
    {
        mVec.push_back(itm);
    }
}

inline void writeFile(vector<int> &mVec)
{
    ofstream f("outFile.txt", std::ios::out);

    vector<int>::iterator it;

    for (it = mVec.begin(); it != mVec.end(); ++it)
    {
        f << *it;
        f << "\n";
    }
}

int main()
{
    vector<int> mVec;

    readFile(mVec);

    std::sort(mVec.begin(), mVec.end());

    writeFile(mVec);

    return 0;
}
