#include<iostream>
using namespace std;
class RefCountMgr 
{ 
	public: 	
	RefCountMgr():m_ref_count(0){} 	
	void incrementRefCount(){ ++m_ref_count; } 	
	void decrementRefCount() { --m_ref_count; } 	
	int getRefCount() const {return m_ref_count;}
	  private: 	
	int m_ref_count; 
}; 
template<typename T> 
class SharedPointer 
{ 
	public:
	 	SharedPointer():m_t(0),m_ref_count_mgr(0){}
	 	SharedPointer(T* t):m_t(t) 	
	 	{ 		
	  	 m_ref_count_mgr = new RefCountMgr();
		 	m_ref_count_mgr->incrementRefCount(); 	
	 	} 	
	 	~SharedPointer() 	
	 	{ 		
	 		if(m_ref_count_mgr) 		
	 		{
	  			m_ref_count_mgr->decrementRefCount();
	  			if(m_ref_count_mgr->getRefCount() <= 0)
	  			{ 				
	  				delete m_t; 				
	  				m_t = 0; 				
	  				delete m_ref_count_mgr;
	  				m_ref_count_mgr = 0; 			
	  			} 		
	  	} 	
	  } 	
	  SharedPointer(const SharedPointer& other)
 	 { 		
 	 	m_t = other.m_t; 		
 	 	m_ref_count_mgr = other.m_ref_count_mgr;
  		m_ref_count_mgr->incrementRefCount(); 	
  	} 	
  	SharedPointer& operator=(const SharedPointer& other) 	
  	{ 		
  		if(this == &other) 			return *this; 		
  	  this->~SharedPointer(); 		
  	  m_t = other.m_t; 		
  	  m_ref_count_mgr = other.m_ref_count_mgr; 		
  	  m_ref_count_mgr->incrementRefCount(); 		
  	  return *this; 	
  	} 	
  	int refcount() const 	
  	{ 		
  		if(m_ref_count_mgr) 
  		return m_ref_count_mgr->getRefCount(); 		
  		return 0; 	
  	} 	
  	T& operator*() const 	{ 		return *m_t; 	} 	  T* operator->() const 	{ 		return m_t; 	} 
  	private: 	
  	RefCountMgr* m_ref_count_mgr; 	
  	T* m_t; 
};
int main()
{
	SharedPointer<int> sp1(new int);
	SharedPointer<int> sp2 = sp1;
	SharedPointer<int> sp3;
	sp3 = sp2;
	SharedPointer<int> sp4(new int);
	SharedPointer<int> sp5 = sp4;
	cout<<"sp1 = "<<sp1.refcount()<<endl;
	cout<<"sp2 = "<<sp2.refcount()<<endl;
	cout<<"sp3 = "<<sp3.refcount()<<endl;
	cout<<"sp4 = "<<sp4.refcount()<<endl;
	cout<<"sp5 = "<<sp5.refcount()<<endl;
	return 0;
} 
