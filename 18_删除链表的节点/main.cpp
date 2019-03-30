#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
        if(pHead==nullptr)
            return pHead;
        ListNode *pNode = pHead;
        ListNode *pPre = nullptr;
        ListNode *pNext = nullptr;
        ListNode *pDel =nullptr;

        while(pNode!=nullptr){
            bool needDel = false;
            pNext = pNode->next;

            if(pNext!= nullptr && pNext->val == pNode->val)
                needDel = true;

            if (!needDel){
                pPre = pNode;
                pNode = pNode->next;
            }
            else{
                int val = pNode->val;
                pDel = pNode;
                while (pDel!= nullptr && pDel->val == val){
                    pNext = pDel->next;
                    delete pDel;
                    pDel = pNext;
                }
                if (pPre == nullptr)    // 如果头节点重复
                    pHead = pNext;
                else
                    pPre->next = pNext;
                pNode = pNext;
            }
        }
        return pHead;
    }
};


int main(int argc, char** argv) {
    Solution sol;
    ListNode* node1= new ListNode(1);
    ListNode* head = node1;
    node1->next = new ListNode(2);
    node1 = node1->next;
    node1->next = new ListNode(2);
    node1 = node1->next;
    node1->next = new ListNode(3);
    node1 = node1->next;
    node1->next = new ListNode(3);
    node1 = node1->next;
    node1->next = new ListNode(4);

    ListNode* r = sol.deleteDuplication(head);

    return 0;
}

