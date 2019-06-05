#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 *
 * 时间复杂度O(logn) 空间复杂度O(1)
 */
class Solution {
public:
    int getNumberOfK(vector<int> nums, int k){
        if(nums.empty()) return 0;
        int ret = 0;
        int left = 0, right = nums.size()-1;

        int leftIndex = -1;  // k元素最左位置
        int rightIndex = -1; // k元素最右位置
        // 查找最左边的k元素位置
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid]<k)
                left = mid+1;
            else if(nums[mid] >k)
                right = mid -1;
            else{
                if((mid > 0 && nums[mid-1] != k )|| mid == 0){
                    leftIndex = mid;
                    break;
                }else
                    right = mid -1;
            }
        }

        if(leftIndex == -1) return 0;    // 没有出现

        // 查找最右边的k元素位置
        left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid]<k)
                left = mid+1;
            else if(nums[mid] >k)
                right = mid -1;
            else{
                if((mid < nums.size()-1 && nums[mid+1] != k) || mid == nums.size()-1){
                    rightIndex = mid;
                    break;
                }else
                    left = mid + 1;
            }
        }
        return rightIndex - leftIndex + 1;
    }
};

int main(){
    vector<int> nums = {1,2,3,3,3,4,5};
    Solution sol;
    int ret = sol.getNumberOfK(nums,3);
    cout << ret << endl;
    return 0;
}

