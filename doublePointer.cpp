#include <iostream>     
#include <thread>
#include <atomic>
using namespace std;
void f1(){cout<<"f1"<<endl;}
int main()
{
  int** a = NULL;
  a = new int*[2];
  for(int i = 0; i < 2; i++)
    *(a + i) = new int[3];
  
  int c = 0;
  for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < 3;j++)
    {
      *(*(a + i) + j) = ++c;
      cout<<*(*(a + i) + j)<<" ";
    }
    cout<<endl;
  }
  int *y = NULL;
  for(int i = 0; i < 2; i++)
  {
    y = *(a + i);
    for(int j = 0; j < 3; j++)
      cout<<*(y + j)<<" ";
    cout<<endl;
  }
	return 0;
}
