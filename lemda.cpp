#include<iostream>
#include<complex>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
	for_each(v.begin(), v.end(), [](int i)
		{
		 cout<<i<<" ";
		});
		cout<<endl;
}
int main()
{
  // Store a generalized lambda, that squares a number, in a variable
  /*auto func = [](auto input) { return input * input; };

  // Usage examples:
  // square of an int
  cout << func(10) << std::endl;

  // square of a double
  cout << func(2.345) << std::endl;

  // square of a complex number
  cout << func(complex<double>(3, -2)) << endl;

  auto size = [](auto i) {
  	return ((char*)(&i + 1) - (char*)&i ); 
  		};
  cout<<"size int = "<<size(2)<<endl;
  cout<<"size char = "<<size('c')<<endl;
  cout<<"size float = "<<size((float)0.2)<<endl;
  cout<<"size double = "<<size(2.2)<<endl;*/
  ////////////////////////////////////////
  	
  vector<int> v = {1, 2, 3, 4};
  
  [&]()
  {
    //print(v);
    for(auto it = v.begin(); it != v.end(); it++)
    {
    	cout<<*it<<" "<<endl;
    }	
  };
  return 0;
}
