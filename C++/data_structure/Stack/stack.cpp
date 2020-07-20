#include <stdio.h>
#include <iostream>

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
    int top_;
    int data_[MAX];
};

Stack::Stack() : top_(-1)
{
}

bool Stack::push(int x)
{
    if (top_ > MAX - 1)
    {
        printf("Stack Overflow\n");
        return false;
    }
    else
    {
        data_[++top_] = x;
        // printf("data_ in push is : %d\n", data_[top_]);

        return true;
    }
}

int Stack::pop()
{
    if (top_ < 0)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    else
    {
        return data_[top_--];
    }
}

int Stack::peek()
{
    if (top_ < 0)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    else
    {
        return data_[top_];
    }
}

bool Stack::isEmpty()
{
    return top_ < 0;
}

int main(int argc, char const *argv[])
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << s.pop() << " Popped from stack\n";
    std::cout << "peek value in stack is: " << s.peek() << "\n";

    // int a = 5;
    // int b = 5;
    // printf("a++ is : %d\n", a++);
    // printf("a is : %d\n", a);
    // printf("++b is : %d\n", ++b);
    // printf("b is : %d\n", b);

    return 0;
}
