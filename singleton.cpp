#include<iostream>
using namespace std;
class mySingleton
{
	int i = 5;
	public:
	int geti(){return i;}
	static mySingleton& getInstance()
	{
		static mySingleton obj;
		return obj;
	}
	private:
	mySingleton(){};
	mySingleton(const mySingleton& obj){};
};
int main()
{
	cout<<mySingleton::getInstance().geti()<<endl;
	mySingleton &obj = mySingleton::getInstance();
	cout<<obj.geti()<<endl;
	mySingleton &obj1 = obj;
	cout<<obj1.geti()<<endl;
	return 0;
}
