#include <stack>
#include <iostream>
// #include <queue>
#include <bits/stdc++.h> 

using namespace std;
class Queue
{
    public:
        void enQueue(int x)
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            s1.push(x);

            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }

        int deQueue()
        {
            if(s1.empty())
            {
                return INT_MIN;
            }


            int ret = s1.top();
            s1.pop();
            return ret;
        }
    private:
        stack<int> s1;
        stack<int> s2;
};


int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    return 0;
}
