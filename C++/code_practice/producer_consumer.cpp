#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;

mutex mx;
condition_variable cv;
bool ready = false;
queue<int> q;

void producer()
{
    unique_lock<mutex> lck(mx);
    q.push(1);
    cout << "front num: " << q.front() << endl;
    ready = true;
    cv.notify_one();
}

void consumer()
{
    unique_lock<mutex> lck(mx);
    cv.wait(lck, []() { return ready; });
    while (!q.empty())
    {
        cout << "consuming " << q.front() << endl;
        q.pop();
    }
}

int main()
{
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();
    return 0;
}
