#include <cstdio>

class Proxy
{
    public: 
        Proxy() = default;
        ~Proxy() = default;

        virtual void marry() = 0;
}; 

class WeddingCompany : public Proxy
{
    private:
        Proxy* proxy;
    public: 
        WeddingCompany() = default;
        ~WeddingCompany() = default;

        WeddingCompany(Proxy* proxyInterface)
        {
            this->proxy = proxyInterface;
        }

        void marry() override
        {
            printf("我们是婚庆公司的\n");
            printf("我们在做结婚前的准备工作\n");
            printf("节目彩排...\n");
            printf("礼物购买...\n");
            printf("工作人员分工...\n");
            printf("可以开始结婚了\n");
            this->proxy->marry();
            printf("结婚完毕，我们需要做后续处理，你们可以回家了，其余的事情我们公司来做\n");
        }
};

class Normal : public Proxy
{
    public: 
        Normal() = default;
        ~Normal() = default;

        void marry() override
        {
            printf("我们结婚啦～\n");
        }
};

int main(int argc, const char * argv[])
{
    Proxy * proxy = new WeddingCompany(new Normal());
    proxy->marry();
}