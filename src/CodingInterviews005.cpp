//
// Created by chester on 19-4-15.
// 替换字符串中的空格
//

#include <iostream>
#include <vector>
using namespace std;

#define __tmain main

class Solution
{
public:
    void replaceSpace(char *str,int length)
    {
        int count = 0;
        for(int i = 0; i < length; i++)
        {
            if (str[i] == ' ') count++;
        }

        int len = length + count*2;
        for(int i = length - 1, j = len - 1; i>=0 && j>=0;)
        {
            if(str[i] != ' ')
            {
                str[j--] = str[i--];
            } else
            {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
                i--;
            }

        }
        str[len] = '\0';

    }
};

int __tmain( )
{
    char str[10 + 1] = "a b c d";

    Solution solu;
    solu.replaceSpace(str, 10);

    cout <<str <<endl;

    return 0;
}