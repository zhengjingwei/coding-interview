#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 蓄水池抽样算法
 * 流式到达的N个数据中选择K个数据，并且N个数据中每个被选中的概率为K/N
 */
class Solution{
public:
    vector<int> getKnumberRand(vector<int> &nums, int k){

        if(k<1 || k> nums.size() || nums.empty())
            return ret;
        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            ret.push_back(nums[i]);             // 前k个直接选择
        }
        for (int i = k; i < nums.size(); ++i) {
            if(rand() % i <= k-1)               // 决定是否选择nums[i]
                ret[rand()%k] = nums[i];        // nums[i]随机替换掉选定的k个中的一个
        }
    }
};


int main(){
    return 0;
}