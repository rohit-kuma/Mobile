//Need to make for all data dype
#include<iostream>
#include<vector>
#include<bits/stdc++.h> 
using namespace std;
vector<void*> v;
template<typename T> class memory
{
	public:
	T* sptr;	
	int val,v2;
	static int v3;
	memory()
	{
		sptr = new T;
		val = 0;
		cout<<"constructor called"<<endl;
	}
	void* operator new(size_t size)
	{
		cout<<"New Operator called"<<endl;
		cout<<"size = "<<size<<endl;
		void* ptr = malloc(size);
		v.push_back(ptr);
		return ptr;
	}
	void* operator new[](size_t size)
	{
		cout<<"New Operator called"<<endl;
		cout<<"size = "<<size<<endl;
		void* ptr = malloc(size);
		v.push_back(ptr);
		return ptr;
	}
	void operator delete(void *ptr)
	{
		cout<<"Operator delete Called"<<endl;
		free(ptr);
		v.erase(remove(v.begin(), v.end(), ptr), v.end());
		int sizev = v.size();
		if(sizev)
		{
			cout<<"Memory Leak "<<sizev<<" units"<<endl;
		}
		else
		{
			cout<<"No memory leak"<<endl;
		}
	}
	void operator delete[](void *ptr)
	{
		cout<<"Operator delete Called"<<endl;
		free(ptr);
		v.erase(remove(v.begin(), v.end(), ptr), v.end());
		int sizev = v.size();
		if(sizev)
		{
			cout<<"Memory Leak "<<sizev<<" units"<<endl;
		}
		else
		{
			cout<<"No memory leak"<<endl;
		}
	}

	~memory()
	{
		cout<<"Destructor Called"<<endl;
	  delete sptr;
	}
};
int main()
{
	//memory<int> *ptr = new memory<int>[4];
	//ptr->val = 10;
	memory<int> obj;
	//cout<<"value = "<<ptr->val<<endl;
	//delete []ptr;
	//int *ptr2 = new int;
  return 0;
}
