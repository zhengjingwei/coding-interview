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
public: // 时间复杂度O（n）
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1== nullptr || pHead2 == nullptr)
            return nullptr;

        ListNode *pNode1 = pHead1;
        ListNode *pNode2 = pHead2;
        int len1 = 0;
        int len2 = 0;
        while (pNode1!= nullptr){   // 计算第一个链表长度
            ++len1;
            pNode1 = pNode1->next;
        }
        while (pNode2!= nullptr){   // 计算第一个链表长度
            ++len2;
            pNode2 = pNode2->next;
        }

        pNode1 = pHead1;
        pNode2 = pHead2;

        int i = 0;
        // 让较长链表先走一段距离；使两个链表剩余长度相等
        if (len1>len2){
            while (i< len1 - len2){
                pNode1 = pNode1->next;
                ++i;
            }
        } else if(len1<len2){
            while (i< len2 - len1){
                pNode2 = pNode2->next;
                ++i;
            }
        }

        while (pNode1!= nullptr && pNode2!= nullptr){
            if(pNode1 == pNode2)
                return pNode1;
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }

        return nullptr;
    }
};


int main(int argc, char** argv) {

    Solution sol;
    return 0;

}

