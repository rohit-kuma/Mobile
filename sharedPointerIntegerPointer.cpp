#include<iostream>
using namespace std;
template<typename T>
class sharedPointer
{gives
	T* ptr;
	int* refcount;
	public:
	sharedPointer()
	{
		cout<<"No Argument Constructor Called"<<endl;
		ptr = nullptr; 
		refcount = nullptr;
	}
	sharedPointer(T* obj)
	{
		cout<<"Argument Constructor Called"<<endl;
		ptr = obj;
		refcount = new int;
		*refcount = 1;
	}
	sharedPointer(const sharedPointer &obj)
	{
		cout<<"Copy Constructor Called"<<endl;
			  ptr = obj.ptr;
			  refcount = obj.refcount;
			  (*refcount)++;
	}
	sharedPointer& operator=(const sharedPointer& obj)
	{
		cout<<"= operator Called"<<endl;
		if(this != &obj)
		{
			if(nullptr != refcount)
			  this->~sharedPointer();
			ptr = obj.ptr;
			refcount = obj.refcount;
			(*refcount)++;
		}
		return *this;
	}
	~sharedPointer()
	{
		cout<<"Destructor Called"<<endl;
		if(nullptr != refcount)
		{
			cout<<"refcount = "<<*refcount<<endl;
			(*refcount)--;
			if(0 == *refcount)
			{
				cout<<"Object Deleted"<<endl;
				delete refcount;
				delete ptr;
			}
		}
	}
};
int main()
{
	sharedPointer<int> sp1(new int);
	sharedPointer<int> sp2 = sp1;
	sharedPointer<int> sp3;
	sp3 = sp1;
  return 0;
}
