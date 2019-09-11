#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock_guard
#include <stdexcept>      // std::logic_error
#include <chrono>
#include <semaphore.h>
#define MAX 100
using namespace std;
void consumer(mutex &mtx, int& top, int* buffer, int id, sem_t& Full, sem_t& Empty)
{
    cout<<"Consumer ID: "<<id<<endl;
    int count = 0;
    while(1)
    {
      sem_wait(&Full); 
      unique_lock<mutex> lock(mtx);
      count++;
      cout<<"Consumer:: "<<id<<" value = "<<buffer[top]<<endl;
      buffer[top--] = 0;
      //if(10 == count) break;
      lock.unlock();
      sem_post(&Empty);
    }
}
void producer(mutex &mtx, int& top, int* buffer, int id, sem_t& Full, sem_t& Empty)
{
    cout<<"Producer ID: "<<id<<endl;
    int count = 0;
    while(1)
    {
      sem_wait(&Empty);
      unique_lock<mutex> lock(mtx);
      count++;
      buffer[top + 1] = top + 1;
      cout<<"Producer:: "<<id<<"value = "<<++top<<endl;
      //this_thread::sleep_for(chrono::seconds(1));
      //if(10 == count) break;
      lock.unlock();
      sem_post(&Full);
    }
}
int main()
{
    sem_t Full, Empty;
    sem_init(&Full, 0, 0); 
    sem_init(&Empty, 0, MAX); 
    int buffer[MAX] = {0};
    int top = -1;
    mutex mtx, mtx1;
    thread t1[10], t2[10];
    for(int id = 0; id < 10; id++)
      t1[id] = thread(producer, ref(mtx), ref(top), buffer, id, ref(Full), ref(Empty));
    this_thread::sleep_for(chrono::seconds(1));
    for(int id = 0; id < 10; id++)
      t2[id] = thread(consumer, ref(mtx), ref(top), buffer, id, ref(Full),ref(Empty));
    for(int id = 0; id < 10; id++)
    {
      t1[id].join();
      t2[id].join();
    }
    sem_destroy(&Full); 
    sem_destroy(&Empty); 
    return 0;
}
