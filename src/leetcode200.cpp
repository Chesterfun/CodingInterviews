//
// Created by shmil on 2019/9/12.
// 岛屿数量
// 方法：深度优先搜索（DFS）、广度优先受伤（BFS）
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        vector<vector<int>> mark;
        for (int i = 0; i < grid.size(); ++i) {
            mark.push_back(vector<int>());
            for (int j = 0; j < grid[i].size(); ++j) {
                mark[i].push_back(0);
            }
        }
        for (int k = 0; k < grid.size(); ++k) {
            for (int i = 0; i < grid[k].size(); ++i) {
                if (mark[k][i] == 0 && grid[k][i] == '1') {
                    DFS(grid, mark, k, i);
                    num++;
                }
            }
        }
        return num;
    }

private:
    void DFS(vector<vector<char>> &grid, vector<vector<int>> &mark, int x, int y){
        mark[x][y] = 1;
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x < 0 || new_x >= mark.size() || new_y < 0 || new_y >= mark[new_x].size()) {
                continue;
            }
            if (mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1') {
                DFS(grid, mark, new_x, new_y);
            }
        }
    }

    void BFS(vector<vector<char>> &grid, vector<vector<int>> &mark, int x, int y){
        mark[x][y] = 1;
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        queue<pair<int, int>> Q;
        Q.push(make_pair(x, y));
        while (!Q.empty()) {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            for (int i = 0; i < 4; ++i) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if (new_x < 0 || new_x >= mark.size() || new_y < 0 || new_y >= mark[new_x].size()) {
                    continue;
                }
                if (mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1') {
                    Q.push(make_pair(new_x, new_y));
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }
};

int main(){
    vector<vector<char>> grid;
    char str[10][10] = {"11100", "11000", "00100", "00011"};
    for (int i = 0; i < 4; ++i) {
        grid.push_back(vector<char>());
        for (int j = 0; j < 5; ++j) {
            grid[i].push_back(str[i][j]);
        }
    }

    Solution solution;
    cout << solution.numIslands(grid) << endl;
    return 0;
}