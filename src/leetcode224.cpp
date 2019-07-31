//
// Created by chester on 19-7-31.
// 基本计算器：实现一个基本的计算器来计算一个简单的字符串表达式的值。
// 字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格。
// 思路：状态转换法
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        static const int STATE_BEGIN = 0;
        static const int NUMBER_STATE = 1;
        static const int OPERATION_STATE = 2;
        stack<int> number_stack;
        stack<char> operation_stack;
        int number = 0;
        int STATE = STATE_BEGIN;
        int compuate_flag = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ')
                continue;
            switch (STATE) {
                case STATE_BEGIN:
                    if (s[i] >= '0' && s[i] <= '9')
                        STATE = NUMBER_STATE;
                    else
                        STATE = OPERATION_STATE;
                    i--;
                    break;
                case NUMBER_STATE:
                    if (s[i] >= '0' && s[i] <= '9') {
                        number = s[i] - '0' + number * 10 ;
                    }
                    else {
                        number_stack.push(number);
                        if (compuate_flag == 1) {
                            compute(number_stack, operation_stack);
                        }
                        number = 0;
                        i--;
                        STATE = OPERATION_STATE;
                    }
                    break;
                case OPERATION_STATE:
                    if (s[i] == '+' || s[i] == '-') {
                        operation_stack.push(s[i]);
                        compuate_flag = 1;
                    }
                    else if (s[i] == '(') {
                        STATE = NUMBER_STATE;
                        compuate_flag = 0;
                    }
                    else if (s[i] >= '0' && s[i] <= '9') {
                        STATE = NUMBER_STATE;
                        i--;
                    }
                    else if (s[i] == ')') {
                        compute(number_stack, operation_stack);
                    }
                    break;
            }
        }

        if (number != 0) {
            number_stack.push(number);
            compute(number_stack, operation_stack);
        }
        if (number == 0 && number_stack.empty()) {
            return 0;
        }
        return number_stack.top();

    }

private:
    void compute (stack<int> &number_stack, stack<char> &operation_stack) {
        if (number_stack.size() < 2)
            return;
        int num2 = number_stack.top();
        number_stack.pop();
        int num1 = number_stack.top();
        number_stack.pop();
        if (operation_stack.top() == '+')
            number_stack.push(num1 + num2);
        else if (operation_stack.top() == '-')
            number_stack.push(num1-num2);
        operation_stack.pop();
    }
};

int main() {
    string s1 = "2147483647";
    string s2 = " ( 1+(4+5+ 2)- 3)+(6+8)";
    Solution solu;
    cout << s1 << " = " << solu.calculate(s1) << endl;
    cout << s2 << " = " << solu.calculate(s2) << endl;
    return 0;
}