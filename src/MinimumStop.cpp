//
// Created by chester on 19-8-6.
// poj2431，最优加油方法：一条公路上,有一个起点与一个终点,这之间有n个加油站;
// 已知从这n个加油站到终点的距离d与各个加油站可以加油的量l ,起点位置至终点的距离L与起始时刻油箱中汽油量P ;假设使用1个单位的汽油即走1个单位的距离,
// 油箱没有上限, 最少加几次油 ,可以从起点开至终点?(如果无法到达终点,返回-1)
// Sample Input：
// 4                                        //代表有n=4个加油站
// 4 4                                      //这一行开始到倒数第二行代表每一站离终点的距离和可加的油量（不是按照加油站前后顺序出现的）
// 5 2
// 11 5
// 15 10
// 25 10                                   //最后一行代表起点站到终点站距离和起始油量
// Sample Output：
// 2
// 思路：贪心思想。尽量先走到能走到的离自己最远的地方，在油用光的之前，在油量最多的加油站加油最合适!
// 算法步骤：
// 1.设置一个 最大堆 ,用来存储经过的加油站的 汽油量 。
// 2.按照从 起点 至 终点 的方向, 遍历 各个加油站之间与加油站到终点距离。
// 3.每次 需要 走两个加油站之间的距离d,如果发现汽油不够走距离d时,从最大堆中 取出 一个油量 添加 ,直到可以 足够 走距离d。
// 4.如果把最大堆的汽油都添加 仍然不够 行进距离d,则 无法达到 终点。
// 5.当前油量P 减少 d。
// 6.将当前加油站油量添加至 最大堆 。

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first;
}

int get_mimimum_stop (int L, int P, vector<pair<int, int>> &stop) {      //L为起点到终点的距离， P为起始点的油量，pair<加油站至终点距离，可加汽油量>
    priority_queue<int> Q;                                               //储存油量的最大堆
    int result = 0;                                                      //记录加过几次油
    stop.push_back(make_pair(0,0));                                      //重点作为一个停靠点添加至stop数组
    sort(stop.begin(), stop.end(), cmp);                                 //以停靠点至终点的距离由远到近排序
    for (int i = 0; i < stop.size(); ++i) {                              //遍历各个加油站
        int dis = L - stop[i].first;                                     //需要走的距离（即到当前加油站的距离）
        while (!Q.empty() && P < dis) {                                  //当油箱的油不支持走到加油站且之前还有加油站可以加油
            P += Q.top();                                                //选择储量最多的加油站加油
            Q.pop();                                                     //加油的这个油站从堆中弹出
            result++;                                                    //记录加油次数加1
        }
        if (Q.empty() && P < dis) {                                      //之前所有的油站油量都没有剩余了而当前可用油量还不支持走到加油站
            return -1;                                                   //说明到达不了终点
        }
        P = P - dis;                                                     //走到一个新的油站油量相应减少
        L = stop[i].first;                                               //更新L为当前油站至终点的距离
        Q.push(stop[i].second);                                          //将当前油站的汽油量储存在最大堆
    }
    return result;
}

int main() {
    vector<pair<int,int>> stop;
    int N;
    int L;
    int P;
    int distance;
    int fuel;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &distance, &fuel);
        stop.push_back(make_pair(distance, fuel));
    }
    scanf("%d %d", &L, &P);
    printf("%d\n", get_mimimum_stop(L, P, stop));
    return 0;
}