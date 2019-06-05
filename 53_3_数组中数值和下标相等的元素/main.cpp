#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 二分查找
 * 时间复杂度O(logn) 空间复杂度O(1)
 */
class Solution {
public:
    int getNumberSameAsIndex(vector<int> nums){
        if(nums.empty()) return 0;
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] ==  mid)
                return mid;
            else if(nums[mid] < mid)
                left = mid + 1; // 右区间
            else
                right = mid - 1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {-3,-1,1,3,5};
    Solution sol;
    cout << sol.getNumberSameAsIndex(nums) << endl;
    return 0;
}

