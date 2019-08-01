//
// Created by chester on 19-8-1.
// 分发饼干：假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
// 对每个孩子 i ，都有一个胃口值 gi ，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j ，都有一个尺寸 sj 。
// 如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
// 例如： 输入: [1,2,3], [1,1] 输出: 1
// 你有三个孩子和两块小饼干，由于两块小饼干的尺寸都是1，你只能让胃口值是1的孩子满足。
// 总体思路：贪心算法
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());                             //对孩子的需求因子g和饼干大小s数组排序
        sort(s.begin(), s.end());
        int child = 0;                                        //child 代表正在尝试的孩子的index，夜即满足的孩子的个数
        int cookie = 0;                                       //cookie 代表正在尝试的饼干的index
        while (child < g.size() && cookie < s.size()) {
            if (g[child] <= s[cookie]) {                      //当饼干能满足孩子需求时
                child++;                                      //孩子index向后移动
                cookie++;                                     //饼干Index也向后移动，即代表用这个饼干满足这个孩子
            }
            else {
                cookie++;                                     //否则这个饼干满足不了任何一个孩子的需求，直接饼干指针向后移动，
            }                                                 //相当于放弃这个饼干，接下来尝试用后面的饼干满足孩子的需求
        }
        return child;                                         //孩子index从0开始，每满足一个+1，也即满足的孩子个数
    }
};

int main() {
    vector<int> g = {4,5,2,3};
    vector<int> s = {1,3,2,6};
    Solution solu;
    int child_num = solu.findContentChildren(g,s);
    cout << child_num << endl;
    return 0;
}
