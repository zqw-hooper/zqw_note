#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int *p = new int();
    *p = 67;
    cout << "The first value is : " << *p << endl;
    int temp = 78;
    int* p1 = new int();
    *p1 = temp;
    cout << "The second value is : " << *p1 << endl;
    int *p2 = new int(89);
    cout << "The third value is : " << *p2 << endl;
    int temp1 = 90;
    int* p3 = nullptr;   //野指针:指向垃圾内存的指针. 产生原因:指针变量未初始化.
    *p = temp1;
    cout << "The forthth value is : " << *p3 << endl;
    return 0;
}