//
// Created by chester on 19-5-9.
// 字节跳动面试题，找出一串字符串里出现次数最多的字符串并统计其出现的次数
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    unordered_map<char, int> findMaxTimes(string str)
    {
        unordered_map<char , int> res;

        if (str.empty())
        {
            res[str[0]] = 0;
            return res;
        }

        unordered_map<char , int> hash;

        int maxTime = 1;
        char resChar;
        for (int i = 0; i < str.size(); ++i) {

            if (hash.find(str[i]) != hash.end())
            {
                cout << str[i] << endl;
                if((hash[str[i]] = ++hash[str[i]])  > maxTime)
                {
                    maxTime = hash[str[i]];
                    resChar = str[i];
                    cout << "maxTime=" << maxTime <<" for "<< str[i] << endl;
                }

            }
            else
            {
                hash[str[i]] = 1;
            }

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
