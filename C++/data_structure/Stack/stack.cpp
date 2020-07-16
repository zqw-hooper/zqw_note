#include <stdio.h>
const int MAX = 1000;

class Stack
{
public:
    Stack();
    ~Stack() = default;

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();

private:
    int top;
    int data[MAX];
};

Stack::Stack() : top(-1)
{
}

bool Stack::push(int x)
{
    if (top > MAX - 1)
    {
        printf("Stack Overflow\n");
        return false;
    }
    else
    {
        int index = top++;
        data[index] = x;
        return true;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
