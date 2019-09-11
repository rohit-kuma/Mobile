#include<iostream>
using namespace std;
class B
{
	public:
	void fun1(){cout<<"Bfun1"<<endl;}
};
class D: public B
{
	public:
 void fun1(){cout<<"Dfun1"<<endl;}
};
int main()
{
	D d;
	B b= d;
	d.fun1(); 
	return 0;
}
