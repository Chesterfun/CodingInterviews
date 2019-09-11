//
// Created by shmil on 2019/9/11.
// 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
// 示例：
// 输入: pattern = "abba", str = "dog cat cat dog"
// 输出: true
//

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> word_map;             //单词与字母对应的map
        unordered_map<char, int> used_map;                //每个字母是否用过的map
        istringstream input(str);
        string tempStr;
        int pos = 0;                                              //标记str第几个单词或者pattern中第几个字母
        while (getline(input, tempStr, ' ')) {      //以空格隔开获取每一个单词
            if (pos == pattern.length()) {                        //如果pattern里的字母遍历完了但是str里还有单词，则不匹配
                return false;
            }
            if (word_map.find(tempStr) != word_map.end()) {      //如果当前的单词已经出现过
                if (word_map[tempStr] != pattern[pos]) {         //如果出现过但是与之前对应的字母不一致，则不匹配
                    return false;
                }
            } else {                                            //如果当前的单词没出现过
                if (used_map[pattern[pos]] == 1) {              //当前的单词没出现过但是pattern中对应的这个字母已经被用过了，则不匹配
                    return false;
                } else {                                        //单词没出现过也没被用过
                    word_map[tempStr] = pattern[pos];           //word_map中添加这个单词与字母的对应
                    used_map[pattern[pos]] = 1;                 //对应的字母标记为被用过
                }
            }
            pos++;
        }
        if (pos != pattern.length()) {
            return false;
        }
        return true;
    }
};

int main(){
    string str = "dog dog cat cat bee fish";
    string pattern = "ddccbg";
//    getline(cin, str);
//    getline(cin, pattern);
    Solution solu;
    cout << solu.wordPattern(pattern, str) << endl;
    return 0;
}