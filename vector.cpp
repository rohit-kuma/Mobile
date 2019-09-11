#include<iostream>
#include<vector>
using namespace std;
struct A { 
	A() = default ; 
	A( int ii, const std::string& ss ) : i(ii), str(ss) 
	{ 
		std::cout << "construct object from args\n" ; 
	} 
	A( const A& that ) : i(that.i), str(that.str)   { 
		std::cout << "copy object\n" ; 
		} 
		int i = 0 ; 
		string str ; 
}; 
void display(vector<A> &v)
{
	for(auto i: v)
	 cout<<i.i<<" "<<i.str<<endl;
	cout<<endl;
	cout<<"Size "<<v.size()<<endl;
	cout<<"Capacity "<<v.capacity()<<endl;
	cout<<"Max Size "<<v.max_size()<<endl;
}
int main () 
{ 
	vector<A> seq ; 
	seq.reserve(10) ; 
	A a ; 
	seq.push_back(a) ; // copy object into the container 
	seq.insert( seq.end(), a ) ; // copy object into the container 
	cout << "-------------\n" ; 
	seq.push_back( A( 10, "hello" ) ) ; // construct an anonymous object // copy (or move) the anonymous object into the container // destroy the anonymous object 
	cout << '\n' ; 
	seq.insert( seq.end(), A( 10, "hello" ) ) ; // construct an anonymous object // copy (or move) the anonymous object into the container // destroy the anonymous object 
	cout << "-------------\n" ; 
	seq.emplace_back( 10, "hello" ) ; // construct the object in-place in the container
	seq.emplace( seq.end(), 10, "hello" ) ; // construct the object in-place in the container 
	cout << "-------------\n" ;
	display(seq); 
}
