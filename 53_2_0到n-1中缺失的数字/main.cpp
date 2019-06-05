#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 转化为二分查找第一个值与下标不相等的元素
 * 时间复杂度O(logn) 空间复杂度O(1)
 */
class Solution {
public:
    int getMissingNumber(vector<int> nums){
        if(nums.empty()) return 0;
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] != mid){
                if(mid == 0 || (mid>0 && nums[mid-1]==mid-1))   // 如果元素与坐标不等且前一个元素与坐标相等
                    return mid;                                 // 则该元素为第一个值与下标不相等元素
                right = mid -1; // 左区间
            } else
                left = mid + 1; // 右区间
        }
        if (left == nums.size()-1)  // 缺的是最后一个元素
            return nums.size()-1;

        return -1;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> nums2 = {0,1,3,4,5,6};
    Solution sol;
    cout << sol.getMissingNumber(nums) << endl;
    cout << sol.getMissingNumber(nums2) << endl;
    return 0;
}

