//
// Created by chester on 19-5-1.
// memcpy,memmove,memset的实现
//
#include <iostream>
#include <stddef.h>
using namespace std;

void *memcpy(void *dst, const void *src, size_t n)
{
    char * dp = (char *) dst;
    const char * sp = (const char *) src;

    while (n--)
        *dp++ = *sp++;

    return dst;

}

void *memmove(void *dst, const void *src, size_t n)
{
    char * dp = (char *)dst;
    const char * sp = (const char *)src;

    if (sp>dp)
    {
        while (n--)
            *dp++ = *sp++;
    }
    else
    {
        dp = dp+n-1;
        sp = sp+n-1;
        while (n--)
            *dp-- = *sp--;
    }
    return dst;
}

void *memset(void *dst, int value, size_t n)
{
    void * dp = dst;
    while(n--)
    {
        * (char *)dst = (char) value;
        dst = (char *)dst + 1;
    }
    return dp;
}

int main ()
{
    char s1[] = "abcde";
    cout<<s1<<endl;

    memcpy(s1,s1+2,3);
    cout<<s1<<endl;

    memmove(s1+2,s1,3);
    cout<<s1<<endl;

    memset(s1,69,5);
    cout<<s1<<endl;

}

