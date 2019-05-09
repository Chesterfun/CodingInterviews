//
// Created by chester on 19-5-9.
// 字节跳动面试题，找出一串字符串里出现次数最多的字符串并统计其出现的次数
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> findMaxTimes(string str)
    {
        unordered_map<char , int> res;
        const char *p = str.c_str();
        if (str.size()==0)
        {
            res[*p] = 0;
            return res;
        }

        unordered_map<char , int> hash;

        int maxTime = 1;
        char resChar;
        for (int i = 0; i < str.size(); ++i) {

            if (hash.find(*p) != hash.end())
            {
                //cout << *p << endl;
                if((hash[*p] = ++hash[*p])  > maxTime)
                {
                    maxTime = hash[*p];
                    resChar = *p;
                    //cout << "maxTime=" << maxTime << *p << endl;
                }

            }
            else
            {
                hash[*p] = 1;
            }
            p++;

        }
        res[resChar] = maxTime;
        return res;
    }

};

int main()
{
    string s1 = "1234fhskwyyy222yy";
    Solution solu;
    unordered_map<char, int> result = solu.findMaxTimes(s1);
    cout << result.begin()->first << " appeared " << result.begin()->second << " times";

    return 0;
}
