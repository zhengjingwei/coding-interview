#include <bits/stdc++.h>
using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


RandomListNode* CreateNode(int val){
    RandomListNode* n1 = new RandomListNode(val);
    return n1;
}

void BuildNodes(RandomListNode* pNode, RandomListNode* pNext, RandomListNode* pRandom){
    pNode->next = pNext;
    pNode->random =pRandom;
}

void printRandomList(RandomListNode *p){
    while(p!= nullptr){
        cout<< p->label <<" ";
        p = p->next;
    }
    cout<<endl;
}



class Solution {
public:
    // 分三步解决；时间复杂度O(n) 相比哈希表法不需要额外空间
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNode(pHead);
        BuildRandomPointer(pHead);
        return SpilitList(pHead);
    }

    // 第一步：复制每个节点，插入到原节点后；
    // 方便建立原始链表节点到新链表对应节点的映射（在原节点后一个节点）
    void CloneNode(RandomListNode* pHead){
        RandomListNode * pNode = pHead;

        while (pNode!=nullptr){
            RandomListNode * pClone = new RandomListNode(pNode->label);
            pClone->next = pNode->next;
            pNode->next = pClone;
            pNode = pClone->next;
        }
    }

    // 第二步：建立新链表的随机指针的指向
    void BuildRandomPointer(RandomListNode *pHead){
        if (pHead== nullptr)
            return ;

        RandomListNode *pNode = pHead;
        RandomListNode *pClone = nullptr;
        while (pNode != nullptr){
            pClone = pNode->next;
            if (pNode->random!=nullptr)
                pClone->random = pNode->random->next; // 新链表random与原始链表random对应
            pNode = pClone->next;
        }
    }

    // 第三步：分割链表，奇数项为原链表，偶数项为复制链表
    // 【注意】需要将原链表恢复；不能破坏原链表 否则无法通过测试
    RandomListNode * SpilitList(RandomListNode* pHead){
        if (pHead == nullptr)
            return pHead;

        RandomListNode *pNode = pHead;
        RandomListNode *pClone = pNode->next;
        RandomListNode *pCloneHead = pNode->next;
        pNode->next = pClone->next; // 将原链表恢复
        pNode = pNode->next;        // 原始链表第二个节点

        while (pNode!= nullptr){
            pClone->next = pNode->next;
            pClone = pClone->next;
            pNode->next = pClone->next;
            pNode = pNode->next;
        }
        return pCloneHead;
    }
};

void Test1(){
    RandomListNode * head, *p;
    RandomListNode * n1 = CreateNode(1);
    RandomListNode * n2 = CreateNode(2);
    RandomListNode * n3 = CreateNode(3);
    RandomListNode * n4 = CreateNode(4);
    RandomListNode * n5 = CreateNode(5);
    RandomListNode * n6 = CreateNode(6);
    head = n1;
    BuildNodes(n1,n2,n3);
    BuildNodes(n2,n3,n6);
    BuildNodes(n3,n4,n5);
    BuildNodes(n4,n5,n2);
    BuildNodes(n5,n6,n4);
    BuildNodes(n6, nullptr, nullptr);
    printRandomList(head);
    cout<<"copyList:"<<endl;
    Solution sol;
    RandomListNode*copyList = sol.Clone(head);
    printRandomList(copyList);
}

int main()
{
    Solution sol;
    Test1();
    return 0;
}

