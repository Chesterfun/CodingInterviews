//
// Created by chester on 19-6-10.
//
// 编写一个函数来查找字符串数组中的最长公共前缀
// 如果不存在公共前缀，返回空字符串 ""

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int minLen = strs[0].length();
        int index = 0;
        string ans = "";
        for (int i = 0; i < strs.size(); ++i) {
            if(strs[i].length()<minLen)
            {
                minLen = strs[i].length();
                index = i;
            }

        }

        for (int j = 0; j < strs[index].length() && ans.length() == j; ++j) {
            for (int i = 0; i < strs.size() && (strs[index][j] == strs[i][j]); ++i)
            {
                if(i==strs.size()-1)
                    ans += strs[index][j];
            }
        }

        return ans;
    }

    string longestCommonPrefixReference(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int index = 0; index < strs[0].size(); ++index) {
            for (int i = 0; i < strs.size(); ++i) {
                if (strs[i][index] != strs[0][index])
                    return strs[0].substr(0,index);
            }
        }
        return strs[0];
    }
};

int main()
{
    Solution solu;
    vector<string> ss = {"aca" , "cba"};
    string s = solu.longestCommonPrefixReference(ss);
    cout << s << endl;
    return 0;
}

