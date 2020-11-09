#include <cstdio>
#include <limits.h>
#include <iostream>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap
{
public:
    MinHeap(int capacity);
    ~MinHeap() = default;

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    int getMin()
    {
        return harr_[0];
    }

    void insertKey(int k);
    void decreaseKey(int i, int new_value);
    int extractMin();
    void minHeapify(int i);
    void deleteKey(int i);
    void printHeap();
    bool isMinHeap();
    void convert2MaxHeap();
    void maxHeapify(int i);

private:
    int size_;
    int capacity_;
    int *harr_;
};

MinHeap::MinHeap(int capacity)
{
    capacity_ = capacity;
    size_ = 0;
    harr_ = new int[capacity];
}

void MinHeap::printHeap()
{
    for (int i = 0; i < size_; ++i)
        std::cout << harr_[i] << " ";
    std::cout << "\n";
}

void MinHeap::insertKey(int k)
{
    if (size_ == capacity_)
    {
        printf("Overflow: Could not insertKey\n");
        return;
    }

    size_++;
    int i = size_ - 1;
    harr_[i] = k;

    while (i != 0 && harr_[parent(i)] > harr_[i])
    {
        swap(&harr_[parent(i)], &harr_[i]);
        i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val.  It is assumed that new_val is smaller than harr_[i]
void MinHeap::decreaseKey(int i, int new_value)
{
    harr_[i] = new_value;
    while (i != 0 && harr_[parent(i)] > harr_[i])
    {
        swap(&harr_[parent(i)], &harr_[i]);
        i = parent(i);
    }
}

void MinHeap::minHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest_index = i;
    if (l < size_ && harr_[l] < harr_[smallest_index])
    {
        smallest_index = l;
    }

    if (r < size_ && harr_[r] < harr_[smallest_index])
    {
        smallest_index = r;
    }

    if (smallest_index != i)
    {
        swap(&harr_[smallest_index], &harr_[i]);
        minHeapify(smallest_index);
    }
}

int MinHeap::extractMin()
{
    if (size_ <= 0)
    {
        return INT_MAX;
    }

    if (size_ == 1)
    {
        size_ = 0;
        return harr_[0];
    }

    int root = harr_[0];

    harr_[0] = harr_[size_ - 1];
    size_--;
    minHeapify(0);
    return root;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

bool MinHeap::isMinHeap()
{
    // all non leaf node is at index (n/2-1)
    for (int i = size_ / 2 - 1; i >= 0; i--)
    {
        if (harr_[i] > harr_[left(i)])
        {
            return false;
        }

        if (right(i) < size_)
        {
            if (harr_[i] > harr_[right(i)])
            {
                return false;
            }
        }
    }
    return true;
}

void MinHeap::maxHeapify(int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < size_ && harr_[l] > harr_[largest])
    {
        largest = l;
    }

    if (r < size_ && harr_[r] > harr_[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(&harr_[largest], &harr_[i]);
        maxHeapify(largest);
    }
}

void MinHeap::convert2MaxHeap()
{
    for (int i = size_ / 2 - 1; i >= 0; i--)
    {
        maxHeapify(i);
    }
}

int main(int argc, const char *argv[])
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    // std::cout << h.extractMin() << " ";
    // std::cout << h.getMin() << " ";
    // h.decreaseKey(2, 1);
    // std::cout << h.getMin();
    // std::cout << h.isMinHeap() << "\n";
    h.printHeap();

    h.convert2MaxHeap();
    h.printHeap();

    return 0;
}