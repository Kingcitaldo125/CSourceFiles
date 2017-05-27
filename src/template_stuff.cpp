#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <class T>
class MyClass
{
private:
	vector<T> elems;
public:
	MyClass();
	~MyClass();
	void printMembers();
	void pushMember(T& member);
	void popMember(T& member);
};

template <class T>
MyClass<T>::MyClass()
{
	
}

template <class T>
MyClass<T>::~MyClass()
{
	
}

template <class T>
void MyClass<T>::printMembers()
{
	int i;
	for(i=0; i<elems.size(); ++i)
	{
		cout << elems[i] << endl;
	}
}

template <class T>
void MyClass<T>::pushMember(T& member)
{
	elems.push_back(member);
	cout << "Pushed " << member << " to collection." << endl;
}

template <class T>
void MyClass<T>::popMember(T& member)
{
	elems.pop(member);
	cout << "Popped " << member << " from collection." << endl;
}

int main()
{
	MyClass<int>* mcc = new MyClass<int>();
	
	int memb = 7;
	int memc = 8;
	int memd = 9;
	
	mcc->pushMember(memb);
	mcc->pushMember(memc);
	mcc->pushMember(memd);
	
	mcc->printMembers();
	
	delete mcc;
	
	return 0;
}
