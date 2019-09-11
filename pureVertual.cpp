#include<iostream>
using namespace std;
class observer
{ 
	public: virtual void notify() = 0;
};
class observer_concrete : public observer
{ 
	public: 
	virtual void notify()// override 
	{
		cout<<"notify of observer concrete"<<endl; 
	}
};
int main()
{
	observer_concrete obj;
	observer *o = &obj;
	o->notify();
  return 0;
}
