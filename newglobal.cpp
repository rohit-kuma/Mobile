#include<iostream>
#include<vector>
#include<bits/stdc++.h> 
using namespace std;
vector<void*> v;
void* operator new(size_t size)
{
		cout<<"New Operator called"<<endl;
		cout<<"size = "<<size<<endl;
		void* ptr = malloc(size);
		v.push_back(ptr);
		return ptr;
}	

int main()
{
	int* ptr = new int;
  return 0;
}
