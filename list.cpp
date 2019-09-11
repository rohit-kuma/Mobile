#include<iostream>
#include<list>
using namespace std;
void display(list<int> &l)
{
	for(auto &i: l)
	 cout<<i<<" ";
	cout<<endl;
}	
int main()
{
	list<int> l{3,4,9,2};
	auto itr = l.insert(l.begin(), 6);
	l.emplace(l.begin(), 5);
	l.push_front(5);
	cout<<"size = "<<l.size()<<endl;
	//remove is done in list with value
	//but in vector we need to spacify the begin and end iterator and the value.
	l.remove(5);
	cout<<"size = "<<l.size()<<endl;
	//erase removes with the value at particular iterator or between two iterator and return is the iterator pointing to next of ersaed value
	//Note: we cant do arithmetic operation on iterator of list like vectors
	auto itr2 = l.erase(l.begin());
	//l.erase(l.begin(), l.end());
	//remove if only takes one parameter as function pointer or functor
	l.remove_if([](const int &i){return (i%2 == 0);});
	//resize takes 1 or 2 paarameter 
	//1st parameter is the size to which size to change and second is the value to be assigned after resizing if resize length is greater the privious length
	l.resize(7, 99);
	display(l);
	cout<<*itr2<<endl;
	//merge takes 1 or 2 argument, first is another list and second is comperator function ptr
	list<int> l2 = {9,6,8,1};
	l.merge(l2,[](const int &i, const int &j){return i<j;});
	cout<<"l2 after merge in l"<<endl;
	display(l2);
	//splice takes 2 or 3 or 4 parameters
	//1st is position where to trasnfer
	//2nd is the list which to transfer
	//3rd: iterator which to transfer
	//4th is the final iterator such that 3rd iterator and 4th iterator range will be trasfered
	display(l);
	list<int> l3 {55,66,33};
	l.splice(l.begin(), l3);
	display(l3);
	display(l);
	cout<<"assign in l4"<<endl;
	list<int> l4(l.begin(), l.end());
	display(l4);
	list<int> l5 = l4;
	return 0;
}
