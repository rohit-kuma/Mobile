#include<iostream>
#include<thread>
using namespace std;
void fun()
{
	cout<<"in thread function"<<endl;
	cout<<"new thread id = "<<this_thread::get_id();
}
int main()
{
 int a = 5;int b =6;
 int &c = a;
 int *p = &b;
 c = b;
 unsigned char d = 0;
 while(d<256)
 {cout<<"hi";d++;}
 cout<<c<<a<<*p;
 return 0;
}
