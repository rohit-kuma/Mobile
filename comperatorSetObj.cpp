#include<iostream>
#include<set>
using namespace std;
/*class A;
template<typename type>
class comp
{
	public:
	bool operator()(const type t1, const type t2)
	{
		return t1 < t2;
	}
	friend bool operator<(const A& obj1, const A& obj2) const {return obj1.i < obj2.i;}
};*/
class A
{
	int i;
	public:
	A(int j = 0){ i = j;}
	int geti(){return i;}
	bool operator<(const A& obj) const 
	{
		return i > obj.i;
	}
};
void display(auto &s)
{
	for(A i : s)
	 cout<<i.geti()<<" ";
	cout<<endl;
}
int main()
{
	A a[5] = {6,8,7,4,5};
	set<A> s1;
	A b(9);
	A obj(1);
	s1.insert(b);
	s1.insert(obj);
	for(int i = 0; i < 5; i++)
	 s1.insert(a[i]);
	display(s1);
	return 0;
}
