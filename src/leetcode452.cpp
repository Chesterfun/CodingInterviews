//
// Created by chester on 19-8-5.
// 用最少的箭引爆气球：已知在一个平面上有一定数量的气球,平面可以看作一个坐标系,在平面的x轴的不同位
// 置安排弓箭手向y轴方向射箭,弓箭可以向y轴走无穷远;
// 给定气球的宽度 xstart ≤ x ≤ xend （因为弓箭可以向y轴走向无穷远，因此不需要考虑y轴坐标）,问至少需要多少弓箭手,将全部气球打爆?
// 例如: 四个气球 : [[10,16], [2,8], [1,6], [7,12]],至少需要2个弓箭手，分别在x=[2,6],x=[10,12]之间射出弓箭。
// 思路：对各个气球按左端点坐标从小到大排序， 遍历气球数组，同时维护一个射击区间，在满足可以将当前气球射穿的同时尽可能击穿更多的气球。
// 每击穿一个新的气球，更新一次射击区间。如果新的气球没办法击穿了，则需要增加一个弓箭，同时维护的射击区间也要更新。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), cmp);
        int shoot_begin = points[0][0];
        int shoot_end = points[0][1];
        int shoot_num = 1;

        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] <= shoot_end) {                //当新的气球左端点在射击区间右端点左边时，射击区间应从新的左端点开始能保证同时击穿新气球
                shoot_begin = points[i][0];
                if (points[i][1] < shoot_end) {             //并且新气球右端点在射击区间右端点左边时（这个时候新气球区间是原来维护的射击区间的子区间)
                    shoot_end = points[i][1];               //更新新的射击区间右端点
                }
            }
            else {                                          //否则新气球的左端点在维护的射击区间的右边时，就需要新的弓箭击穿这个新气球
                shoot_num++;
                shoot_begin = points[i][0];
                shoot_end = points[i][1];
            }
        }

        return shoot_num;
    }
};

int main() {
    vector<int> num0 = {10, 16};
    vector<int> num1 = {2, 8};
    vector<int> num2 = {1, 6};
    vector<int> num3 = {7, 12};
    vector<vector<int>> nums = {num0,num1,num2,num3};
    Solution solu;
    cout << solu.findMinArrowShots(nums) << endl;
    return 0;
}
