#include<iostream>
#include<vector>
#include<initializer_list>
#include <assert.h> 
using namespace std;
class dog
{
	string name;
	int age;
	public:
	dog(string name1, int age1)
	{
		name = name1;
		age = age1;
	}
	void display()
	{
		cout<<"name = "<<name<<" age = "<<age<<endl;
	}
};
void foo(int i){cout<<"foo(int) called"<<endl;}
void foo(char *i){cout<<"foo(char*) called"<<endl;}
void enumclass()
{
	//03
	/*enum apple {a,b};
	enum orange {c,d};
	apple a1 = a;
	orange o1 = c;
	if(a1 == o1) cout<<"same"<<endl;
	else cout<<"not same"<<endl;*/
	//11 compilation error as == operator not defined
	// enum class apple {a,b};
	// enum class orange {c,d};
	// apple a1 = apple::a;
	// orange o1 = orange::c;
	// if(a1 == o1) cout<<"same"<<endl;
	// else cout<<"not same"<<endl;
}
void assertKT()
{
	int a = 5;
	int *ptr = &a;
	//ptr = NULL;
	//03
	assert(ptr != NULL); //run time assert: if flase code following it dont run
	cout<<"assert sucess"<<endl;
	
	//11
	//sizeof(int) == 4 is called constant expression
	static_assert(sizeof(int) == 4, "static assert fail"); //compile time assert: if false code following it dont compile
	cout<<"static assert sucess"<<endl;
}
void delegating_constructor()
{
	class dog
	{
		int age = 5; // 11 we can initilise like this
		public:
		dog(){cout<<"No arg cons called"<<endl;}
		dog(int i):dog(){cout<<"first no ag cons will be called then arg con will be called with value = "<<i<<endl;}
	};
	dog d1;
	dog d2(6);
}
void overrideKeyword()
{
	class dog
	{
		public:
		virtual void A(int){cout<<"A1"<<endl;}
		virtual void B() const{cout<<"B1"<<endl;}
		void C(){cout<<"C1"<<endl;}
	};
	class yellowDog: public dog
	{
		public:
		/*void A(float f) override {cout<<"A with value "<<f<<endl;} //type mismatch error
		void B() override {cout<<"B"<<endl;} //type mismatch error
		void C() override {cout<<"C"<<endl;}*/ //compilation error on using override keyword for non virtual function
	};
	yellowDog obj;
	dog *ptr = &obj;
	ptr->C();
	ptr->A(2);
}
void finalkeyword()
{
	cout<<"when final key word is used after class name and after member function then the class cant be inherited and function cant be overridden"<<endl;
}
void compilerGeneratedDefaultConstructor()
{
	//03
	class dog
	{
		public:
		dog(int a){} //compiler dont provide default constructor if any constructor user has defined
	};
	//dog d; //will fail due to above reson
	
	class cat
	{
		public:
		cat(int a){} //compiler dont provide default constructor if any constructor user has defined
		cat() = default;
	};
	cat d; //will fail due to above reson
}
void deleteKeyWord()
{
	class dog{
		dog& operator=(dog&) = delete;
	};
	cout<<"delete a function"<<endl;
}
int main()
{
	vector<int> v {1,2,3,4};
	dog d{"tom", 4};
	d.display();
	for(auto i: v)
		cout<<i<<" ";
	cout<<endl;
	for(auto &i: v)
		i++;
	cout<<endl;
	for(auto i: v)
		cout<<i<<" ";
	cout<<endl;
	/////////////
	//foo(NULL); //conflict
	foo(nullptr);
	//////////
	enumclass();
	assertKT();
	delegating_constructor();
	overrideKeyword();
	finalkeyword();
	compilerGeneratedDefaultConstructor();
	deleteKeyWord();
	return 0;
}
