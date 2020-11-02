#include <stdio.h>
#include <iostream>
#include <mutex>

std::mutex mu;
#if 0
class Singleton{
    public:
        static Singleton &getInstance()
        {
            static Singleton obj;
            return obj;
        }

        void singleton_print(int a)
        {
            printf(" input int is :%d\n", a);
        }

    private:
        Singleton() { printf("Singleton construct!\n"); }
        ~Singleton() { printf("Singleton deconstruct!\n"); }

        Singleton(Singleton &obj) = delete;
        Singleton &operator=(Singleton &obj) = delete;
};
#elif 0

// 线程不安全版本
class Singleton
{
    private:
        Singleton() { printf("Singleton construct!\n"); }
        ~Singleton() { printf("Singleton deconstruct!\n"); }

        public:
            static Singleton* getInstance(){
                if(m_instance == nullptr)
                {
                    m_instance = new Singleton();
                }
            }
            static Singleton* m_instance;
};
Singleton* Singleton::m_instance = nullptr;

#elif 0
// 线程安全，但是锁的代价高
class Singleton
{
    private:
        Singleton() { printf("Singleton construct!\n"); }
        ~Singleton() { printf("Singleton deconstruct!\n"); }

        public:
            static Singleton* getInstance(){
                std::lock_guard<std::mutex> lock(mu);
                if(m_instance == nullptr)
                {
                    m_instance = new Singleton();
                }
            }
            static Singleton* m_instance;
};
Singleton* Singleton::m_instance = nullptr;

#elif 1
//双检查锁
class Singleton
{
private:
    Singleton() { printf("Singleton construct!\n"); }
    // ~Singleton() { printf("Singleton deconstruct!\n"); }

public:
    ~Singleton() { printf("Singleton deconstruct!\n"); }
    static Singleton *getInstance()
    {
        if (m_instance == nullptr) // 第一个判断是为了减少不必要的互斥锁带来的开销，提升性能.
        {
            std::lock_guard<std::mutex> lock(mu);
            if (m_instance == nullptr) // 第二个判断是为了避免多次创建
            {
                m_instance = new Singleton();
            }
        }
        return m_instance;
    }
    volatile static Singleton *m_instance;  // volatile可以防止内存读写reorder不安全 
};
Singleton *Singleton::m_instance = nullptr;
#endif

int main(int argc, char const *argv[])
{
    /* code */
    Singleton* pobj1 = Singleton::getInstance();
    Singleton *pobj2 = Singleton::getInstance();
    if(pobj1 == pobj2)
    {
        printf("two objects equate!\n");
    }
    // delete pobj1;
    delete pobj2;
    // Singleton& pobj2 = Singleton::getInstance();
    // pobj1.singleton_print(1052);
    return 0;
}
