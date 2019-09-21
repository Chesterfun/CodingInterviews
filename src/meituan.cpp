//
// Created by chester on 19-9-18.
// 美团笔试题，输入"true","false","and","or"的组合，返回语句结果，"and"优先级比"or"高；
// 示例输入：
// false and true or false and true
// 输出：false

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

bool getStatus(string str){
    if (str == "true")
        return true;
    return false;
}

int pow(int x, int n) {
    int res = 1;
    for (int i = 0; i < n; ++i) {
        res*=x;
    }
    return res;
}

int main() {
    vector<vector<string>> vec;
    string line;
    for (int i = 0; i < 2; ++i) {
        getline(cin, line);
        vector<string> tmpStr;
        string tmp;
        istringstream input(line);
        while (getline(input, tmp, ' ')) {
            tmpStr.push_back(tmp);
        }
        vec.push_back(tmpStr);
    }

    for (int i = 0; i < vec.size(); ++i) {
        stack<int> res;
        int pushFlag = 1;

        for (int j = 0; j < vec[i].size(); ++j) {

            if (vec[i][j] == "and") {
                pushFlag = 0;
                continue;
            } else if (vec[i][j] == "or") {
                pushFlag = 1;
                continue;
            } else {
                if (pushFlag == 1) {
                    if (vec[i][j] == "true")
                        res.push(1);
                    else if (vec[i][j] == "false")
                        res.push(0);
                } else {
                    int status = res.top() && getStatus(vec[i][j]);
                    res.pop();
                    res.push(status);
                }
                pushFlag = 1;
            }
        }

        string value = "false";
        while (!res.empty()) {
            if (res.top() == 1) {
                value = "true";
                break;
            }
            res.pop();
        }
        if (i<vec.size()-1)
            cout << value << endl;
        else if (i == vec.size() - 1) {
            cout << value;
        }
    }
    return 0;
}