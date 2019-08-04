#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 最长公共子串问题-动态规划
 * dp[i][j]表示在必须将str1[i-1]和str2[j-1]作为公共子串最后一个字符的情况下，公共子串最大长度
 * dp[i][j]取决于dp[i-1][j], dp[i][j-1], dp[i-1][j-1]
 * 时间复杂度O（MN） 空间复杂度O（MN）
 */

class Solution {
public:
    // 最长公共子串长度
    int lengthofLCST(string &str1, string &str2) {
        if(str1.empty() || str2.empty()) return 0;
        vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
        int ret = 0;
        for (int i = 1; i <= str1.size(); ++i) {
            for (int j = 1; j <= str2.size(); ++j) {
                dp[i][j] = str1[i-1] == str2[j-1] ? dp[i-1][j-1]+1 : 0;
                ret = max(ret, dp[i][j]);   // 每次计算完更新最大值
            }
        }
        return ret;
    }

    // 返回最长公共子串
    string longestCommonSubString(string &str1, string &str2) {
        if(str1.empty() || str2.empty()) return "";
        vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
        int maxLen = 0;
        int end = 0;    // 以该位置字符结尾的子串最长
        for (int i = 1; i <= str1.size(); ++i) {
            for (int j = 1; j <= str2.size(); ++j) {
                dp[i][j] = str1[i-1] == str2[j-1] ? dp[i-1][j-1]+1 : 0;
                if (dp[i][j] > maxLen){
                    maxLen = dp[i][j];   // 每次计算完更新最大值
                    end = i-1;
                }
            }
        }
        return str1.substr(end - maxLen + 1, maxLen);
    }

    // 返回最长公共子串：优化算法-空间复杂度O(1)
    // 因为dp[i][j]仅取决于dp[i-1][j-1]
    // 按照平行于对角线的斜线方向计算，只需要一个变量就可以计算出所有位置的值
    string longestCommonSubStringII(string &str1, string &str2) {
        if(str1.empty() || str2.empty()) return "";

        int maxLen = 0;
        int end = 0;    // 以该位置字符结尾的子串最长
        int row = 0, col = str2.size()-1;   // 斜线开始的行，列
        while (row <str1.size()){
            int i = row;
            int j = col;
            int len = 0;
            while (i < str1.size() && j < str2.size()){
                if (str1[i] == str2[j])
                    ++len;
                else
                    len = 0;
                if (len > maxLen){
                    end = i;
                    maxLen = len;
                }
                ++i;
                ++j;
            }

            if(col > 0)
                --col;
            else
                ++row;
        }
        return str1.substr(end - maxLen + 1, maxLen);
    }
};

int main(){
    string str1 = "1AB2345CD", str2 = "12345EF"; // 2345
    Solution sol;
    cout << sol.lengthofLCST(str1, str2) << endl;
    cout << sol.longestCommonSubString(str1, str2) << endl;
    cout << sol.longestCommonSubStringII(str1, str2) << endl;
}

