#include<iostream>
using namespace std;
#define CAPACITY 10
template<class T>
class myVector
{
	int size;
	T *ptr;
	public:
	myVector()
	{
		cout<<"constructor ... "<<endl;
		size = 0;
		ptr = new T[CAPACITY];
	}
	~myVector()
	{
		cout<<"destructor ... "<<endl;
		delete []ptr; 
	}
	void push(T data)
	{
		if(size == CAPACITY)
		{
			cout<<"Vector Full"<<endl;
			return;
		}
		ptr[size] = data;
		size++;
	}
	T pop()
	{
		if(0 == size)
		{
			cout<<"Vector Empty"<<endl;
			return -1;
		}
		size--;
		return ptr[size];
	}
	void print()
	{
		for(int i = 0; i < size; i++)
		cout<<ptr[i]<<" "<<endl;
	}
	int getSize()
	{
		return size;
	}
	int &operator[](int index)
	{
		return ptr[index];
	}
	T& operator*()
	{
		return *ptr;
	}
	T* operator+(int index)
	{
		return ptr + index;
	}
};
int main()
{
  myVector<int> v;
  v.push(99);
  v.push(95);
  v.push(93);
  v.push(91);
  cout<<"size = "<<v.getSize()<<endl;
  v[2] = 777;
  v.print();
  cout<<"* operator "<<*v<<endl;
  *(v + 2) = 666;
  cout<<"+ operator "<<*(v + 2)<<endl;
  cout<<"operator[] "<<v[2]<<endl;
  cout<<"First item = "<<v.pop()<<endl;
  return 0;
}
