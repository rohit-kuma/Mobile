#include<iostream>
#include<vector>
#include<bits/stdc++.h> 
using namespace std;
void display(vector<int> &v)
{
	for(auto i: v)
	 cout<<i<<" ";
	cout<<endl;
	cout<<"size "<<v.size()<<endl;
}
int main()
{
	vector<int> v1{1,2,3,4,5,6};
  v1.erase(remove(v1.begin(),v1.end(),5), v1.end());
  //v1.erase(v1.end() - 2, v1.end());
  display(v1);
  return 0;
}
