//
// Created by chester on 19-7-27.
// 复杂链表的深度拷贝。 复杂链表指的是链表节点的结构除了节点值和指向下一个节点的指针之外，还包含指向一个随机节点的指针
// 思路：题目难点和关键在于复制链表随机节点的指向信息。
// 构造一个源链表的节点指针映射节点index的map；同时构造一个vector，通过vector的index可以获取拷贝的新链表的节点指针
// 新链表每一个节点指向的随机节点的index可以从map中得到，再根据index在vector中获取新链表指向的节点
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        map<Node *, int> node_map;                  //节点指针到节点index的映射
        vector<Node *> node_vec;                    //使用vector根据index访问新链表的节点
        Node *pcur = head;

        int i = 0;
        while(pcur) {
            node_vec.push_back(new Node);           //遍历源链表，建立存储新链表节点的vector
            node_map[pcur] = i;                     //记录源链表节点指针至节点index的映射关系
            pcur = pcur->next;
            i++;
        }

        //cout<<"node_vec size = "<<node_vec.size()<<endl;

        pcur = head;
        i = 0;
        while (pcur) {
            node_vec[i]->val = pcur->val;           //第二次遍历链表，将源链表每个节点的val复制到新链表
            if (i<node_vec.size()-1)                //复制源链表节点的next信息，对最后一个节点的next特殊处理
                node_vec[i]->next = node_vec[i+1];
            else
                node_vec[i]->next = nullptr;
            if(pcur->random) {                      //如果源链表的对应节点存在random指针
                int id = node_map[pcur->random];    //根据node_map获取该节点的random指针的index
                node_vec[i]->random = node_vec[id]; //新的链表random指针同样指向相同的index位置
            }
            else
                node_vec[i]->random = nullptr;      //源链表节点不存在romdom指针则新链表random也为空
            pcur = pcur->next;
            i++;
        }

        return node_vec[0];
    }
};

int main() {
    Node nodelist[5];
    nodelist[0].val = 1;
    nodelist[1].val = 2;
    nodelist[2].val = 3;
    nodelist[3].val = 4;
    nodelist[4].val = 5;
    nodelist[0].next = &nodelist[1];
    nodelist[1].next = &nodelist[2];
    nodelist[2].next = &nodelist[3];
    nodelist[3].next = &nodelist[4];
    nodelist[4].next = nullptr;
    nodelist[0].random = &nodelist[2];
    nodelist[1].random = &nodelist[3];
    nodelist[2].random = &nodelist[2];
    nodelist[3].random = nullptr;
    nodelist[4].random = &nodelist[3];

    Solution solu;
    Node *newhead = solu.copyRandomList(nodelist);
    while(newhead) {
        cout << "val = " << newhead->val;
        if (newhead->random)
            cout << " rand = " << newhead->random->val << endl;
        else
            cout << " rand = NULL" << endl;
        newhead = newhead->next;
    }

    return 0;
}
