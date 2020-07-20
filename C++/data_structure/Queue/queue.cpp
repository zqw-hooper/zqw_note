#include <cstdio>
#include <iostream>

class Queue
{
public:
    Queue(int capacity);
    ~Queue() = default;
    void enqueue(int data);
    void dequeue();
    bool isFull();
    bool isEmpty();
    int front();
    int rear();
    void print();

private:
    int size_;
    int capacity_;
    int front_;
    int rear_;
    int *array_;
};

Queue::Queue(int capacity) : size_(0), capacity_(capacity), front_(-1), rear_(-1)
{
    array_ = new int[capacity_];
}

bool Queue::isFull()
{
    return (this->size_ == this->capacity_);
}

bool Queue::isEmpty()
{
    return (this->size_ == 0);
}

void Queue::enqueue(int data)
{
    front_ = 0;
    if (size_ > capacity_ - 1)
    {
        printf("Queue overfolw\n");
    }
    else
    {
        rear_++;
        array_[size_++] = data;
    }
}

void Queue::dequeue()
{
    if (isEmpty())
    {
        return;
    }

    for (int i = 0; i < size_ - 1; i++)
    {
        array_[i] = array_[i + 1];
    }
    size_--;
    rear_ = size_ - 1;
}

void Queue::print()
{
    for (int i = 0; i < size_; i++)
    {
        printf("Queue element is : %d\n", array_[i]);
    }
}

int Queue::front()
{
    return array_[front_];
}

int Queue::rear()
{
    return array_[rear_];
}

int main(int argc, char const *argv[])
{
    Queue queue(100);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    printf("front element in queue is : %d\n", queue.front());
    printf("rear element in queue is : %d\n", queue.rear());
    queue.print();

    queue.dequeue();
    printf("-------------------\n");
    printf("front element in queue is : %d\n", queue.front());
    printf("rear element in queue is : %d\n", queue.rear());
    queue.print();

    return 0;
}
