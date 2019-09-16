//
// Created by shmil on 2019/9/15.
// 岛屿的最大面积
// 深度优先搜索（DFS）

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> mark;
        for (int i = 0; i < grid.size(); ++i) {
            mark.push_back(vector<int>());
            for (int j = 0; j < grid[i].size(); ++j) {
                mark[i].push_back(0);
            }
        }
        int maxArea = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (mark[i][j] == 0 && grid[i][j] == 1) {
                    int area = 0;
                    int tmp = DFS(grid, mark, i, j, area);
                    if (tmp>maxArea)
                        maxArea = tmp;
                }
            }
        }
        return maxArea;

    }

    int DFS(vector<vector<int>> &grid, vector<vector<int>> &mark, int x, int y, int &area) {
        mark[x][y] = 1;
        if (grid[x][y] == 1){
            area++;
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size()) {
                continue;
            }
            if (grid[new_x][new_y] == 1 && mark[new_x][new_y] == 0) {
                DFS(grid, mark, new_x, new_y, area);
            }
        }
        return area;
    }
};

int main(){
    vector<vector<int>> vec;
    string line;
    int n;                              //输入n行
    cin >> n;
    cin.ignore(1024, '\n');
    for (int i = 0; i < n; ++i) {          //接下来将输入存入vec二维数组
        getline(cin, line);
        vector<int> tmp;
        istringstream input(line);
        string tmpData;
        while (getline(input, tmpData, ' ')) {
            tmp.push_back(stoi(tmpData));
        }
        vec.push_back(tmp);
    }

    Solution solution;
    cout << solution.maxAreaOfIsland(vec) << endl;
    return 0;
}