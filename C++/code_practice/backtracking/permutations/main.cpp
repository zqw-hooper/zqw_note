#include <bits/stdc++.h>

void swap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

void premute(std::string str, int l, int r)
{
    if(l == r)
    {
        std::cout << str << std::endl;
    }
    else
    {
        for(int i = l; i <= r; i++)
        {
            swap(&str[l],&str[i]);
            premute(str, l + 1, r);
            swap(&str[l], &str[i]);
        }
    }
}

int main(int argc, char *argv[]) 
{
    std::string str = "abc";
    premute(str, 0, str.size() - 1);
    return 0; 
}