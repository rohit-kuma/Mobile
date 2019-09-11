#include<iostream>
#include<list>
using namespace std;
class Observer;
class Subject
{
	list<Observer*> observers;
	int numerator;
	public:
	int getValue(){return numerator;}
	void setValue(int val){ numerator = val; notify();}
	void attach(Observer *obs){ observers.push_back(obs);}
	void notify();
};
class Observer
{
	Subject* model;
	int denom;
	public:
	Subject* getModel(){return model;};
	int getDenom(){return denom;}
	Observer(Subject* model, int denom)
	{
		this->model = model;
		this->denom = denom;
		model->attach(this);
	}
	virtual void update() = 0;
};
class divObserver: public Observer
{
	int Num;
	int Den;
	public:
	divObserver(Subject* model, int denom):Observer(model, denom){}//when derived class initilises constructor of base class 
	void update()
	{
		Num = getModel()->getValue();
		Den = getDenom();
		cout<<"Numerator = "<<Num<<" Denom = "<<Den<<" Div = "<<Num/Den<<endl;
	}
};
class modObserver: public Observer
{
	int Num;
	int Den;
	public:
	modObserver(Subject* model, int denom):Observer(model, denom){}
	void update()
	{
		Num = getModel()->getValue();
		Den = getDenom();
		cout<<"Numerator = "<<Num<<" Denom = "<<Den<<" Mod = "<<Num%Den<<endl;
	}
};
void Subject::notify()
{
	for ( list<Observer*>::iterator itr = observers.begin(); itr != observers.end(); itr++ )
	{
		(*itr)->update();
	}
}
int main()
{
	Subject sub;
	divObserver ob1(&sub, 2);
	modObserver ob2(&sub, 3);
	modObserver ob3(&sub, 2);
	sub.setValue(14);
	return 0;
}
