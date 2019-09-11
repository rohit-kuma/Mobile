#include<algorithm>
#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
void display(auto &v)
{
	for(int &i: v)
	 cout<<i<<" ";
	cout<<endl;
}
int main()
{
	vector<int> vin {1,2,3,4};
	vector<int> vout(vin.size());
	transform(vin.begin(), vin.end(), vout.begin(), [](int &i){return i*3;});
	display(vin);
	display(vout);
	cout<<"size = "<<vout.size()<<endl;
	auto itr = remove_if(vout.begin(), vout.end(),[](int &i){
		if(i % 2 == 0) return true;
		else return false;
	});
	for(auto itr1 = vout.begin(); itr1 != itr; itr1++)
	 cout<<*itr1<<" ";
	cout<<endl;
	cout<<"size = "<<vout.size()<<endl;
	int acc = accumulate(vin.begin(), vin.end(), 1, [](int &i, int &j){return i*j;});
	cout<<"accumulate = "<<acc<<endl;
	return 0;
}
