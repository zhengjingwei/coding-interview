#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 用二维数组缓存中间计算结果
 * 时间复杂度O(n^2) 空间复杂度O(n^2)
 */
class Solution {
public:
    int getMaxValue(vector<vector<int>> nums){
        if(nums.empty() || nums[0].empty()) return 0;
        vector<vector<int>> maxValue(nums.size(), vector<int> (nums[0].size(),0));
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[0].size(); ++j) {
                int left = 0;
                int up = 0;
                if (i>0)
                    up = maxValue[i-1][j];
                if (j>0)
                    left = maxValue[i][j-1];

                maxValue[i][j] = max(up,left) + nums[i][j];
            }
        }
        return maxValue.back().back();
    }
};

/*
 * maxValue[i][j]只与maxValue[i-1][j]和maxValue[i][j-1]相关
 * 因此i-2行及更上面的所有中间结果不必保存
 * 用一维数组缓存中间计算结果
 * 时间复杂度O(n^2) 空间复杂度O(n)
 */
class SolutionII {
public:
    int getMaxValue(vector<vector<int>> nums){
        if(nums.empty() || nums[0].empty()) return 0;
        vector<int> maxValue(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[0].size(); ++j) {
                int left = 0;
                int up = 0;
                if (i>0)
                    up = maxValue[j];
                if (j>0)
                    left = maxValue[j-1];

                maxValue[j] = max(up,left) + nums[i][j];
            }
        }
        return maxValue.back();
    }
};

int main(){
    vector<vector<int>> nums = {{1,10,3,8},
                                {12,2,9,6},
                                {5,7,4,11},
                                {3,7,16,5}};
    Solution sol;
    cout <<sol.getMaxValue(nums) << endl;
    return 0;
}

