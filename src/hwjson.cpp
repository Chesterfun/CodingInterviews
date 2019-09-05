//
// Created by chester on 19-9-5.
//

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    string json;
    stack<char> ccdd;
    ccdd.push(' ');
    set<int> errors;
    for (string line; getline(cin, line); ) {
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        json += line;
    }
    for (size_t i = 0; i < json.size(); ++i) {
        char c = json[i];
        switch (c) {
            case '{': ccdd.push(c); break;
            case '}':
                if (ccdd.top() != '{') {
                    errors.insert(2);
                } else if (ccdd.top() == '}') {
                    ccdd.pop();
                } else if (json[i + 1] == '{') {
                    errors.insert(4);
                } break;
            case '[': ccdd.push(c); break;
            case ']':
                if (ccdd.top() != '{') {
                    errors.insert(1);
                } else if (ccdd.top() == ']') {
                    ccdd.pop();
                } else if (json[i + 1] != '}' && json[i+1] == '"') {
                    errors.insert(4);
                } break;
            case '\"': {
                if ((json[i + 1] >= 'a' && json[i + 1] <= 'z') ||
                    (json[i + 1] >= 'A' && json[i + 1] <= 'Z') ||
                    json[i + 1] == '_') {
                    ccdd.push('\"');
                } else if (json[i + 1] == ':' || json[i + 1] == '\n' || json[i + 1] == ',' || json[i + 1] == '}') {
                    if (ccdd.top() != '\"') {
                        errors.insert(3);
                    } else {
                        ccdd.pop();
                    }
                } else if (json[i + 1] == '\"') {
                    errors.insert(4);
                }
            } break;
        }
    }
    for (size_t i = 0; i < ccdd.size() - 1; ++i) {
        char c = ccdd.top();
        switch (c) {
            case '{':
            case '}': errors.insert(2); break;
            case '[':
            case ']': errors.insert(1); break;
            case '"': errors.insert(3); break;
        }
        ccdd.pop();
    }
    for (auto e : errors) cout << e;

    return 0;
}