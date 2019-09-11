#include<iostream>
using namespace std;
class observer
{
	observer *ptr;
	public:
	observer()
	{
		cout<<"Base & "<<this<<endl;
		ptr = this;
	}
};
class denobserver: public observer
{
	public:
	denobserver():observer()
	{
		cout<<"Derived & "<<this<<endl;
	}
	void registero(){}
	void unregistero(){}
};
int main()
{
	denobserver obj;
	cout<<"& "<<&obj<<endl;
  return 0;
}
