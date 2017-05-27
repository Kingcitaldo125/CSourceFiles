#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> myvec;
	myvec.push_back("Paul");
	myvec.push_back("Harold");
	myvec.push_back("Lenny");
	myvec.push_back("Gary");
	
	vector<string>::iterator it;
	//int i=0;
	for(it=myvec.begin();it<myvec.end();++it)
		cout << *it << endl;
	
	return 0;
}