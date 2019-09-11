
#include<iostream>
using namespace std;
class Copy
{
	public:
	/*Copy( Copy &&c)
	{
		cout<<"Move constructor ..."<<endl;
	}*/
	~Copy(){}
};

int main()
{
  Copy c;//(Copy());
  Copy c1 = move(c);
  return 0;
}
