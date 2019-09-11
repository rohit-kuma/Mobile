#include<iostream>
using namespace std;
template<class T>
class uniquePointer
{
	T *ptr;
	public:
	uniquePointer(T *p = NULL)
	{
		ptr = p;
	}
	~uniquePointer()
	{
		delete ptr;
	}
	uniquePointer(const uniquePointer &p ) = delete;
	uniquePointer operator =(uniquePointer p) = delete;
	int &operator*(){return *ptr;}
};
int main()
{
	uniquePointer<int> ptr(new int(10));
	uniquePointer<int> p1;// = ptr;
	//p1 = ptr;
  cout<<*ptr<<endl;
  *ptr = 20;
  cout<<*ptr<<endl;
  return 0;
}
