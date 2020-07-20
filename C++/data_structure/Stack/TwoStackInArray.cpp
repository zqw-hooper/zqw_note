#include <stdio.h>
#include <iostream>

class TwoStack
{
public:
    TwoStack(int size);
    ~TwoStack() = default;
    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();

private:
    int top1_;
    int top2_;
    int *data_;
    int size_;
};

TwoStack::TwoStack(int size) : top1_(-1), top2_(size), size_(size)
{
    data_ = new int[size_];
}

void TwoStack::push1(int x)
{
    if (top1_ > top2_ - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        data_[++top1_] = x;
        printf("first part data is :%d\n", data_[top1_]);
    }
}

void TwoStack::push2(int x)
{
    if (top1_ > top2_ - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        data_[--top2_] = x;
        printf("second part data is :%d\n", data_[top2_]);
    }
}

int TwoStack::pop1()
{
    if (top1_ > -1)
    {
        return data_[top1_--];
    }
    else
    {
        std::cout << "Stack UnderFlow";
        return 0;
    }
}

int TwoStack::pop2()
{
    if (top2_ < size_)
    {
        return data_[top2_++];
    }
    else
    {
        std::cout << "Stack UnderFlow";
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    TwoStack two_stack(20);
    two_stack.push1(1);
    two_stack.push1(2);
    two_stack.push1(3);
    two_stack.push1(4);

    two_stack.push2(9);
    two_stack.push2(8);
    two_stack.push2(7);
    two_stack.push2(6);
    printf("pop from first part data is :%d\n", two_stack.pop1());
    printf("pop from first part data is :%d\n", two_stack.pop1());
    printf("pop from first part data is :%d\n", two_stack.pop1());
    printf("pop from first part data is :%d\n", two_stack.pop1());
    printf("pop from first part data is :%d\n", two_stack.pop1());

    printf("pop from second part data is :%d\n", two_stack.pop2());
    printf("pop from second part data is :%d\n", two_stack.pop2());
    printf("pop from second part data is :%d\n", two_stack.pop2());
    printf("pop from second part data is :%d\n", two_stack.pop2());
    printf("pop from second part data is :%d\n", two_stack.pop2());

    return 0;
}
