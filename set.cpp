#include<iostream>
#include<set>
using namespace std;
void display(auto s)
{
	for(auto i: s)
	 cout<<i<<" ";
	cout<<endl;
}
int main()
{
	set<int> s{2,8,5,6,3};
	set<int> s1(s.begin(), s.end());
	s1.insert(66);
  display(s);
  display(s1);
  return 0;
}
