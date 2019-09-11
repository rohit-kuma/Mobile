#include<iostream>
#include<map>
using namespace std;
template<typename T>
class comp
{
	public:
	bool operator()(const T& first1, const T& second1) //const
	{
		return first1 > second1;
	}
};
void display(auto m)
{
	for(auto i: m)
	 cout<<i.first<<" "<<i.second<<endl;
}
int main()
{
	map<int,int, comp<int>> m1{{3,33},{4,44},{5,55}};
	m1.insert(make_pair(2,22));
	m1.insert(make_pair(2,33));
	m1.insert(pair<int,int>(0,00));
	m1[0]=99;
  display(m1);
  return 0;
}
