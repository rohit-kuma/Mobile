//this code shows refcount cannot be auto int or static int
#include<iostream>
using namespace std;
template<typename T>
class sharedPtr
{
	T* ptr = nullptr;
	int refcount;
	public:
	sharedPtr(){cout<<"default constructor"<<endl;}
	sharedPtr(T *obj)
	{
		cout<<"single arg constructor"<<endl;
		refcount = 1;
		ptr = obj;
	}
	sharedPtr(sharedPtr& obj)
	{
		cout<<"copy constructor called"<<endl;
		if( ( this != &obj) && ( obj.ptr != nullptr) )
		{
			(obj.refcount)++;
			refcount = obj.refcount;
			ptr = obj.ptr;
		}
	}
	sharedPtr& operator=(sharedPtr &obj)
	{
		cout<<"= operator called"<<endl; 
		if( ( this != &obj) && ( obj.ptr != nullptr) )
		{
			cout<<"in = "<<obj.refcount<<endl;
			(obj.refcount)++;
			refcount = obj.refcount;
			ptr = obj.ptr;
		}
	}
	void setvalue(T val){*ptr = val;}
	T getvalue(){return *ptr;}
	int get_count(){return refcount;}
	sharedPtr& operator*(){return *(this->ptr);}
	sharedPtr* operator->(){return this;}
	~sharedPtr()
	{
		cout<<"Destructor called : ref = "<<refcount<<endl;
		refcount--;
		if(0 == refcount)
		{
			cout<<"Memory Deleted"<<endl;
		  delete ptr;
		}
	}
};
//template<typename T>
//int sharedPtr<T>::refcount = 0;
int main()
{
	sharedPtr<int> sp(new int);
	sharedPtr<int> sp1 = sp;
	//sp->setvalue(99);
	//cout<<"Value"<<sp->getvalue()<<endl;
	//cout<<"Value"<<sp1->getvalue()<<endl;
	//cout<<sp1->get_count()<<endl;
	sharedPtr<int> sp2;
	sp2 = sp1;
	cout<<sp->get_count()<<endl;
	cout<<sp1->get_count()<<endl;
	//sharedPtr<int> sp3(new int);
	cout<<sp2->get_count()<<endl;
	return 0;
}
