//
// Created by shmil on 2019/9/9.
// 实现一个极简解释器，输入第一行为表达式行数，接下来每行为一个表达式，表达式只存在变量名、=、+、空格
// 输出最后一句表达式左边变量的值；如果最后一句表达式不能输出有效值则输出NA

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<string,int> calculate;
int flag = 1;

bool isNumber(string s){
    for (size_t i = 0; i < s.size(); ++i) {
        if (!(s[i]>='0' && s[i]<='9')) {
            return false;
        }
    }
    return true;
}

void getResult(string line, int i, int n) {             //每次处理一行表达式

    istringstream input(line);
    string left;
    getline(input, left, '=');
    left.erase(remove(left.begin(), left.end(), ' '), left.end());          //等号左边的字符串去掉空格
    string right;
    getline(input, right);
    right.erase(remove(right.begin(), right.end(), ' '), right.end());  //等号右边的字符串去掉空格

    int plusNum = 0;
    for (size_t j = 0; j < right.size(); ++j) {                             //计算等号右边的+数量
        if (right[j] == '+') {
            plusNum++;
        }
    }

    if (plusNum==0) {                                               //如果等号右边只有一个数字或者变量
        if (isNumber(right)) {                                      //如果是数字
            calculate[left] = stoi(right);
        } else {
            if (calculate.find(right) == calculate.end() && i==n) {        //如果是没有出现过的变量则表达式语法错误
                flag = 0;
            }
            if (calculate.find(right) != calculate.end()) {        //否则是出现过的变量，将左边的变量更新
                calculate[left] = calculate[right];
            }
        }
    } else {                                                    //如果右边是一个运算式子
        istringstream rightTemp(right);
        stack<string> nums;
        int k = plusNum ;
        string temp;
        while (k--) {
            getline(rightTemp, temp, '+');
            nums.push(temp);                                    //将右边每个加数存在栈中
        }
        getline(rightTemp, temp);
        nums.push(temp);
        k = plusNum + 1;
        int res = 0;
        while (k--) {
            string tempStr = nums.top();
            if (isNumber(tempStr)) {                            //当这个加数是数字的时候
                res += stoi(tempStr);
            } else if (calculate.find(tempStr) != calculate.end()) {    //当这个加数是之前出现过的变量的时候
                res += calculate[tempStr];
            } else if (calculate.find(tempStr) == calculate.end()){                                            //否则这个加数是之前没有出现过的变量，语法错误
                flag = 0;
            }
            nums.pop();
        }
        calculate[left] = res;
    }

    if (i == n) {                                       //处理到最后一行表达式的时候，输出表达式左边变量的值
        if (flag == 0) {
            cout << "NA";
            return;
        }
        cout << calculate[left];
    }
}


int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    cin.ignore(1024, '\n');
//    string tempstr;
//    getline(cin, tempstr);
    int i = 0;
    while (i++ < n) {
        string line;
        getline(cin, line);
        getResult(line, i, n);
    }

    return 0;
}



