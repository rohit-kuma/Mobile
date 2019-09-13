#include<iostream>

#include<set>

using namespace std;

template<typename type>

class comp
{

	public:

	bool operator()(const type &t1, const type &t2)

	{

		return t1->geti() < t2->geti();

	}

};

class A
{

	int i;

	public:

	A(int j = 0){ i = j;}

	int geti(){return i;}

};

void display(set<A*, comp<A*>> &s)
{

	for(auto &i : s)

	 cout<<i->geti()<<" ";

	cout<<endl;

}

int main()

{

	A a[5] = {6,8,7,4,5};

	set<A*, comp<A*>> s1;

	A b(9);

	A obj(1);

	s1.insert(&b);

	s1.insert(&obj);

	for(int i = 0; i < 5; i++)

	 s1.insert(&a[i]);

	display(s1);

	return 0;

}
