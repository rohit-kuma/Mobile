#include<iostream>
using namespace std;
class test
{
	public:
	test(){cout<<"Default"<<endl;}
	test(const test& t){cout<<"Copy Const"<<endl;}
};
test fun()
{
	cout<<"fun called"<<endl;
	test t;
	return t;
}
int main()
{
	//test t;
	test t1 = fun();
  return 0;
}
