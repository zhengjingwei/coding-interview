#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> nodesStack; // 栈先进后出
        vector<int> ret;
        ListNode *node = head;
        while (node != nullptr){
            nodesStack.push(node->val);
            node = node->next;
        }

        while (!nodesStack.empty()){
            ret.push_back(nodesStack.top());
            nodesStack.pop();
        }
        return ret;
    }
};

void printList(ListNode ** head){
    ListNode *p = *head;
    while(p != nullptr){
        cout<< p->val<<endl;
        p = p->next;
    }
}


int main(int argc, char** argv) {

    ListNode* node1= new ListNode(1);
    ListNode* head = node1;
    node1->next = new ListNode(2);
    node1 = node1->next;
    node1->next = new ListNode(3);

    printList(&head);
    Solution sol;
    vector<int> vec = sol.printListFromTailToHead(head);

    cout<<"reverse:"<<endl;
    for (int i = 0; i < vec.size(); ++i) {
        cout<< vec[i] << endl;
    }
    return 0;
}