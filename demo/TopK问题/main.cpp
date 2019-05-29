#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class SolutionI {
public:
    /*
     * 基于快排Partition函数
     * 时间复杂度O（n）空间复杂度O（1）需要改变输入
     */
    vector<int> getTopK(vector<int> nums, int k){
        if (nums.empty() || k > nums.size() || k<=0) return {};
        vector<int> ret;
        int begin = 0, end = nums.size()-1;
        int idx = Partition(nums,begin,end);
        while (idx != k){
            if (idx < k){
                begin = idx + 1;
                idx = Partition(nums,begin,end);
            }else{
                end = idx - 1;
                idx = Partition(nums,begin,end);
            }
        }

        for (int i = 0; i < k; ++i) {
            ret.push_back(nums[i]);
        }
        return ret;
    }

    // 返回索引值idx，idx前的元素均小于该处的元素值；idx后的元素均大于该处的元素值
    int Partition(vector<int> &nums, int begin, int end){
        if (begin > end) return begin;
        int key = nums[begin];    // 取最后一个值为基准值
        while (begin < end){
            while (nums[end] <= key && begin < end) --end;
            nums[begin] = nums[end];
            while (nums[begin] > key && begin < end) ++ begin;
            nums[end] = nums[begin];
        }
        nums[begin] = key;
        return begin;
    }
};

class SolutionII {
public:
    /*
     * 最小堆方法
     * 时间复杂度O（nlogk）空间复杂度O（k）
     */
    vector<int> getTopK(vector<int>& nums, int k){
        if (nums.empty() || k > nums.size() || k<1) return {};
        vector<int> ret;
        multiset<int, less<int>> m; // 最小堆，保存最大的K个数
        multiset<int, less<int>>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            if(m.size()<k){
                m.insert(nums[i]);
            } else{
                it = m.begin();
                // 如果当前值大于topK的最小元素（最小堆堆顶），替换该值
                if (nums[i]> *it){
                    m.erase(it);
                    m.insert(nums[i]);
                }
            }
        }
        for (it = m.begin();it!=m.end();it++)
            ret.push_back(*it);

        return ret;
    }
};

int main(){
    vector<int> nums = {3,2,4,5,7,4};
    SolutionI sol1;
    vector<int> ret1 = sol1.getTopK(nums,4);
    SolutionII sol2;
    vector<int> ret2 = sol2.getTopK(nums,4);
    return 0;
}

