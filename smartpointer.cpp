#include<iostream>
using namespace std;
class smartPointer
{
	int *ptr;
	public:
	smartPointer(int *p = NULL)
	{
		ptr = p;
	}
	~smartPointer()
	{
		delete ptr;
	}
	int &operator *()
	{
		return *ptr;
	}
};
int main()
{
  smartPointer ptr(new int);
  *ptr = 20;
  cout<<*ptr<<" "<<endl;
  return 0;
}
