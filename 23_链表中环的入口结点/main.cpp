#include <iostream>
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        // 设置快慢指针，如果快指针赶上慢指针，说明有环
        // 快指针每次走2步；慢指针每次走1步
        if(pHead== nullptr)
            return nullptr;
        ListNode* fast = pHead->next;
        ListNode* slow = pHead;
        while(fast!=nullptr && fast!= slow){
            fast = fast->next;
            if (fast!=nullptr)
                fast = fast->next;
            slow = slow->next;

        }
        if (fast==nullptr)
            return nullptr;

        // 计算环的长度
        int loopLen = 1;
        ListNode *lastFast = fast;
        fast = fast->next;
        while(fast!=lastFast){
            fast = fast->next;
            ++loopLen;
        }

        fast = pHead;
        slow = pHead;
        // 让快指针先走loopLen步，慢指针再开始走
        for(int i =0;i<loopLen; ++i){
            fast = fast->next;
        }
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main() {

    ListNode* node1= new ListNode(1);
    ListNode* head = node1;
    node1->next = new ListNode(2);
    node1 = node1->next;
    node1->next = new ListNode(3);
    node1 = node1->next;
    ListNode * n3 = node1;
    node1->next = new ListNode(4);
    node1 = node1->next;
    node1->next = new ListNode(5);
    node1 = node1->next;
    node1->next = n3;

    Solution sol;
    ListNode *pNode = sol.EntryNodeOfLoop(head);
    cout<<pNode->val<<endl;
    return 0;
}