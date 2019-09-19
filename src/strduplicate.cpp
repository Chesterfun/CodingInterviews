//
// Created by shmil on 2019/9/19.
// 字符串去重：给定一个字符串，要求去除其中的重复字符。例如 abcbs ，操作后得到 abcs
// 哈希表，原地更改字符串

#include <bits/stdc++.h>

using namespace std;

void duplicate(string &str)
{
    if(str.size()<2)
        return;
    int len = str.length();
    int tail = 0;
    unordered_map<char, int> hash;

    for (int i = 0; i < len; ++i) {
        if (hash.find(str[i]) == hash.end()) {
            str[tail++] = str[i];
            hash[str[i]] += 1;
        }
    }
    str.erase(tail, len);
}


int main()
{
    string mystr;
    while (cin >> mystr) {
        duplicate(mystr);
        cout << mystr << endl;
    }
    return 0;
}
