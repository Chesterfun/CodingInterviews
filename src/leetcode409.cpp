//
// Created by chester on 19-9-4.
// 最长回文串：给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
// 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int maxLength = 0;
        bool odd_exit = false;
        unordered_map<char, int> hash_map;
        for (int i = 0; i < s.length(); ++i) {
            hash_map[s[i]]++;
        }

        unordered_map<char, int>::iterator it = hash_map.begin();
        while (it != hash_map.end()) {
            if (it->second % 2 == 0) {
                maxLength += it-> second;
            }
            else {
                maxLength += it->second - 1;
                odd_exit = true;
            }
            it++;
        }
        if (odd_exit)
            return maxLength+1;
        return maxLength;
    }
};

int main() {
    string s;
    Solution solu;
    while (cin >> s) {
        if (s == "END!")
            break;
        cout << solu.longestPalindrome(s) << endl;
    }
    return 0;
}