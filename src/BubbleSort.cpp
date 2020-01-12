#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::vector;

inline void readFile(vector<int>& mVec, const char* fName= "inFile.txt")
{
	ifstream f(fName, std::ios::in);

	int itm;

	while (f >> itm)
	{
		mVec.push_back(itm);
	}
}

inline void writeFile(vector<int>& mVec, const char* fName = "outFile.txt")
{
	ofstream f(fName, std::ios::out);

	vector<int>::iterator it;

	for (it = mVec.begin(); it != mVec.end(); ++it)
	{
		f << *it;
		f << "\n";
	}
}


inline double getAvg(vector<int>& mVec)
{
	unsigned int total=0;
	double avg=0.;

	vector<int>::iterator it;

	for (it = mVec.begin(); it != mVec.end(); ++it)
	{
		total += *it;
	}

	avg = static_cast<double> (total / mVec.size());

	return avg;
}


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
			cur = mVec[i]; // 8
			nxt = mVec[i+1]; // 4

			if (cur > nxt)
			{
				int holdr;
				holdr = nxt; // 4
				nxt = cur; // 8
				cur = holdr; // 4

				mVec[i] = cur;
				mVec[i+1] = nxt;

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

	//int minElement, maxElement;

	//auto mm = std::minmax_element(mVec.begin(), mVec.end());
	//minElement = *mm.first;
	//maxElement = *mm.second;

	//cout << "minElement: " << minElement << " maxElement: " << maxElement << "\n";

	//cout << "Avg: " << getAvg(mVec);

	//writeFile(mVec);

	return 0;
}
