#include<iostream>
using namespace std;
template <class T>
class smartPointer
{
	T* ptr;
	public:
	smartPointer(T* p = NULL)
	{
		ptr = p;
	}
	~smartPointer()
	{
		delete ptr;
	}
	T& operator*()
	{
		return *ptr;
	}
	T* operator->()
	{
		return ptr;
	}
};
class value
{
	public:
	int a;
	value(int b = 10)
	{
		a = b;
	}
};
int main()
{
 smartPointer<int> ptr(new int);
 *ptr = 20;
 cout<<*ptr<<endl;
 smartPointer<value> ptr1(new value(30));
 ptr1->a = 55;
 cout<<ptr1->a<<endl;
 smartPointer<int> ptr2;
 //*ptr1 = 40;
 //cout<<*ptr1<<endl;
 return 0;
}
