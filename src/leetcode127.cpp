//
// Created by shmil on 2019/9/15.
// 单词接龙
// 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
// 每次转换只能改变一个字母。
// 转换过程中的中间单词必须是字典中的单词。
// 备注：如果不存在这样的转换序列，返回 0；所有单词具有相同的长度；所有单词只由小写字母组成；字典中不存在重复的单词。
//  beginWord 和 endWord 是非空的，且二者不相同。示例：
// 输入:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// 输出: 5
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <set>


using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> graph;
        constructGraph(beginWord, wordList, graph);
        int step = BFS(beginWord, endWord, graph);
        return step;
    }

private:
    bool connect(string str1, string str2){
        int cnt = 0;
        for (int i = 0; i < str1.size(); ++i) {
            if (str1[i] != str2[i]) {
                cnt++;
            }
        }
        return cnt == 1;
    }

    void constructGraph(string &beginWord, vector<string> &WordList, unordered_map<string, vector<string>> &graph) {
        WordList.push_back(beginWord);
        for (int i = 0; i < WordList.size(); ++i) {
            graph[WordList[i]] = vector<string>();
        }
        for (int i = 0; i < WordList.size(); ++i) {
            for (int j = i+1; j < WordList.size(); ++j) {
                if (connect(WordList[i],WordList[j])) {
                    graph[WordList[i]].push_back(WordList[j]);
                    graph[WordList[j]].push_back(WordList[i]);
                }
            }
        }
    }

    int BFS(string beginWord, string endWord, unordered_map<string, vector<string>>& graph) {
        queue<pair<string, int>> Q;
        Q.push(make_pair(beginWord, 1));
        set<string> visit;
        visit.insert(beginWord);
        while (!Q.empty()) {
            string word = Q.front().first;
            int step = Q.front().second;
            Q.pop();
            if (word == endWord) {
                return step;
            }
            vector<string> neighbor = graph[word];
            for (int i = 0; i < neighbor.size(); ++i) {
                if (visit.find(neighbor[i]) == visit.end()) {
                    Q.push(make_pair(neighbor[i], step + 1));
                    visit.insert(neighbor[i]);
                }
            }
        }
        return 0;
    }
};

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> WordList = {"hot","dot","dog","lot","log","cog"};
    Solution solution;
    int step = solution.ladderLength(beginWord, endWord, WordList);
    cout << step << endl;
    return 0;
}