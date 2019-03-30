#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 环形链表
    // STL中的list只有没有循坏，每次访问到链表末尾时要重新指向链表头
    int LastRemaining_Solution(int n, int m){
        if (n<1 || m<1)
            return 0;

        list<int> nums;
        for (int i = 0; i < n; ++i) {
            nums.push_back(i);
        }

        list<int>::iterator cur = nums.begin();
        while (nums.size()>1){
            for (int i = 1; i < m; ++i) {
                cur++;
                if(cur == nums.end())
                    cur = nums.begin();
            }
            list<int>::iterator next = ++cur;   // 保存下一个节点
            if (next == nums.end())
                next = nums.begin();
            cur--;
            nums.erase(cur);    // 删除该节点
            cur = next;         // 指向下一个节点
        }
        return *(cur);
    }
};

int main(int argc, char** argv) {
    Solution sol;
    cout<<sol.LastRemaining_Solution(5,3)<<endl;
    return 0;
}

