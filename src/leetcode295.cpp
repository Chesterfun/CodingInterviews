//
// Created by chester on 19-7-31.
// 数据流中的中位数。设计一个支持以下两种操作的数据结构：
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。
// double findMedian() - 返回目前所有元素的中位数。
//
// 思路：维护一个最大堆和最小堆，保证最大堆的堆顶元素比最小堆的堆顶元素小，并且两个堆元素个数相同或相差1个元素，则中位数即可由两个堆的堆顶元素求得。
//

#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (big_queue.empty()) {
            big_queue.push(num);
            return;
        }
        if (big_queue.size() == small_queue.size()) {
            if (num <= big_queue.top()) {
                big_queue.push(num);
                return;
            }
            else {
                small_queue.push(num);
            }
        }
        else if (big_queue.size() > small_queue.size()) {
            if (num > big_queue.top()) {
                small_queue.push(num);
            }
            else {
                small_queue.push(big_queue.top());
                big_queue.pop();
                big_queue.push(num);
            }
        }
        else if (big_queue.size() < small_queue.size()) {
            if (num < small_queue.top()) {
                big_queue.push(num);
            }
            else {
                big_queue.push(small_queue.top());
                small_queue.pop();
                small_queue.push(num);
            }
        }
    }

    double findMedian() {
        if (big_queue.size() == small_queue.size()) {
            return (big_queue.top()+small_queue.top())/2.0;
        }
        else if (big_queue.size() > small_queue.size()) {
            return big_queue.top();
        }
        else {
            return small_queue.top();
        }
    }

private:
    priority_queue<double , vector<double>, greater<double>> small_queue;
    priority_queue<double , vector<double>, less<double>> big_queue;
};

int main() {
    MedianFinder *obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    obj->addNum(3);
    obj->addNum(4);
    cout << "Median(1,2,3,4) = " << obj->findMedian() << endl;
    obj->addNum(3);
    cout << "Median(1,2,3,4,3) = " << obj->findMedian() << endl;
    return 0;
}