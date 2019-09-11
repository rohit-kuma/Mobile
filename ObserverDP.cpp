#include<iostream>
#include<list>
using namespace std;
class Observer
{
	int id;
	int score;
	public:
	void display()
	{
		cout<<"ID = "<<id<<" Score = "<<score<<endl;
	}
	void update(int newID, int newData)
	{
		id = newID;
		score = newData;
		display();
	}
};
class Subject
{
	int id;
	int score;
	public:
	list<Observer*> registeredObserver;
	void registerObservers(Observer *ob)
	{
		registeredObserver.push_back(ob);
	}
	void unRegisterObservers(Observer *ob)
	{
		registeredObserver.remove(ob);
	}
	void notifyObservers()
	{
		for(auto it = registeredObserver.begin(); it != registeredObserver.end(); it++ )
		{
			(*it)->update(id, score);
		}
	}
	void dataChange(int newID = 0, int newData = 0)
	{
		id = newID;
		score = newData;
		notifyObservers();
	}
	
};
int main()
{
	Observer ob;
	Subject subObj;
	subObj.registerObservers(&ob);
	subObj.dataChange(99,77);
	subObj.dataChange(991,771);
	subObj.unRegisterObservers(&ob);
	subObj.dataChange(992,772);
	return 0;
}
