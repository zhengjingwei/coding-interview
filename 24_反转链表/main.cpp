#include <iostream>
#include <vector>
#include <random>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

void printList(ListNode ** head){
    ListNode *p = *head;
    while(p != nullptr){
        cout<< p->val<<endl;
        p = p->next;
    }
}


class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {

        if(pHead == nullptr)
            return pHead;

        ListNode *pNode = pHead ->next;
        ListNode *pNext;
        ListNode *pReversedHead = pHead;    // 反转链表的表头
        pReversedHead->next = nullptr;      // 第一个节点指向空指针

        while (pNode != nullptr){

            pNext = pNode->next;            // 原来p节点的下一节点
            pReversedHead = insertHeadNode(&pReversedHead, pNode);  // 将p插入rHead前
            pNode = pNext;
        }
        return pReversedHead;

    }
    ListNode* insertHeadNode(ListNode** pHead, ListNode * node) {
        ListNode *head  = *pHead;
        node->next = head;
        return node;
    }
};



int main(int argc, char** argv) {


    ListNode* node1= new ListNode(1);
    ListNode* head = node1;
    node1->next = new ListNode(2);
    node1 = node1->next;
    node1->next = new ListNode(3);

    printList(&head);

    Solution sol;
    ListNode* aa = sol.ReverseList(head);
    printList(&aa);

    return 0;
}