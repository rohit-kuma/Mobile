#include <iostream>
using namespace std;
class B
{
	public:
	virtual void fun1(){cout<<"Base fun1"<<endl;}
	virtual void fun4(){cout<<"Base fun4"<<endl;}
	void fun3(){cout<<"Base fun3"<<endl;}
};
class D: public B
{
	public:
	virtual void fun1(){cout<<"Derived fun1"<<endl;}
  void fun2(){cout<<"Derived fun2"<<endl;}
  void fun3(){cout<<"Derived fun3"<<endl;}
};
int main()
{
	D obj;
	B *bptr;
	//B &b = obj;
	bptr = &obj;
	D *dptr = dynamic_cast<D*>(bptr); 
	bptr->fun1(); 
	dptr->fun1();
	dptr->fun2();
	bptr->fun3();
	dptr->fun3();	
	dptr->fun4();	
	D *dptr1 = static_cast<D*>(bptr);
	dptr1->fun3();
  //ptr->fun2();
  //b.fun1();
	return 0;
}
