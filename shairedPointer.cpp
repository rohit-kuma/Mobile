#include<iostream>
#include<memory>
using namespace std;
class test
{
	int val = 5;
	public:
	int getval(){return ++val;}
	test(){cout<<"constructor called"<<endl;}
	~test(){cout<<"destructor called"<<endl;}
};
int main()
{
	shared_ptr<test> sp1(new test);
	cout<<"value = "<<sp1->getval()<<endl;
	shared_ptr<test> sp2 = make_shared<test>();
	cout<<"value = "<<sp2->getval()<<endl;
	shared_ptr<test> sp3 = sp2;
	cout<<"value = "<<sp3->getval()<<endl;
	cout<<"count"<<endl;
	cout<<sp1.use_count()<<endl;
  return 0;
}
