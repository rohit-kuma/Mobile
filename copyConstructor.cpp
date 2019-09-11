#include<iostream>
using namespace std;
void fun1()
{
	cout<<"Throw a function"<<endl;
}
int main()
{
	try
	{
	 auto fun = [](){cout<<"Throw a function"<<endl;};
	 throw fun1;
	 //throw [](){cout<<"Throw a function"<<endl;};
	 //through should be inside try block
	 //catch is also requird if some thing is thrown
	}
	catch(void (*pfun)())
	{
		cout<<"Caught All exception"<<endl;
		pfun();
	}
  return 0;
}
