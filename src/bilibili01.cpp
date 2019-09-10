//
// Created by shmil on 2019/9/10.
// bilibili笔试题：给定一个数组由一些非负整数组成，现需要将他们进行排列并拼接，使得最后的结果最大，返回的值需要是string类型，否则可能会溢出
// 输入描述：一行数字，中间以逗号隔开
// 输出描述：一个字符串
// 示例：
// 输入：12,121,5
// 输出：512121

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int &a, int &b){
    string aStr = to_string(a);
    string bStr = to_string(b);
    string ab = aStr + bStr;
    string ba = bStr + aStr;
    return ab > ba;
}

int main(){
    string str;
    getline(cin, str);
    int num = 1;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == ',') {
            num++;
        }
    }
    istringstream input(str);
    string temp;
    vector<int> vec;

    while(num--){
        getline(input, temp, ',');
        vec.push_back(stoi(temp));
    }

    sort(vec.begin(), vec.end(), cmp);
    if (vec[vec.size()-1] == 0) {
        cout << "0";
        return 0;
    }
    for (size_t j = 0; j < vec.size(); ++j) {
        cout << vec[j];
    }

    return 0;
}