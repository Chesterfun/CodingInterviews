//
// Created by chester on 19-6-14.
// 有效的括号。给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
// 分析：利用栈的性质，先进后出，遇左括号则压入栈，遇右括号则与栈顶元素匹配，匹配成功则弹出栈顶元素
//

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        unordered_map<char, char> pair;
        pair.insert({')','('});
        pair.insert({']','['});
        pair.insert({'}','{'});

        stack<char> mystack;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                mystack.push(s[i]);
            else if(s[i]==')' || s[i]==']' || s[i]=='}')
            {
                if(mystack.empty()) return false;

                if(pair[s[i]] == mystack.top())
                {
                    mystack.pop();
                    continue;
                } else
                    return false;
            }
        }

        if (mystack.empty()) return true;
        else
            return false;

    }
};


int main()
{
    string s1 = "[[[(({}))]]]";
    string s2 = "))";
    string s3 = "( i)";

    Solution solu;
    cout << solu.isValid(s1) << endl;
    cout << solu.isValid(s2) << endl;
    cout << solu.isValid(s3) << endl;
    return 0;
}

