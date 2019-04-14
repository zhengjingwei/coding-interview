#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size){
        vector<int> ret;
        if (num.empty() || size<=0 || size>num.size())
            return ret;

        deque<int> index;   // 存放可能成为滑动窗口内最大值的数字下标
        for (int i = 0; i < size; ++i) {
            while (!index.empty() && num[i] >= num[index.back()])
                index.pop_back();   // 弹出从后往前比当前加入值小的元素；这些元素不可能成为窗口最大值
            index.push_back(i);
        }
        ret.push_back(num[index.front()]);
        for (int i = size; i < num.size(); ++i) {
            while (!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            index.push_back(i);

            // 从前向后弹出不在窗口内的值
            while (!index.empty() && index.front() <= i-size)
                index.pop_front();
            ret.push_back(num[index.front()]);
        }

        return ret;
    }
};



int main(){
    vector<int> v = {2,3,4,2,6,2,5,1};
    Solution sol;
    vector<int> ret = sol.maxInWindows(v,3);
    for(auto i:ret)
        cout<<i<<' ';
    return 0;
}

