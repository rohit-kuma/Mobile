#include<iostream>
#include<complex>
#include <vector>
using namespace std;

int main()
{
vector<int> v1 = {3, 1, 7, 9}; 
vector<int> v2 = {10, 2, 7, 16, 9}; 

  

    //  access v1 and v2 by reference 

    auto pushinto = [&] (int m) 

    { 

        v1.push_back(m); 

        v2.push_back(m); 

    }; 

  

    // it pushes 20 in both v1 and v2 

    pushinto(20); 

  

    // access v1 by copy 

    [v1]() 

    { 

        for (auto p = v1.begin(); p != v1.end(); p++) 

        { 

            cout << *p << " "; 

        } 

    }; 



  return 0;
}
