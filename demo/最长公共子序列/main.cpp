#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 最长公共子序列-动态规划
 * dp[i][j]表示str1前i子串和str2前j子串的最长公共子序列长度
 * dp[i][j]取决于dp[i-1][j], dp[i][j-1], dp[i-1][j-1]
 * 时间复杂度O（MN） 空间复杂度O（MN）
 */

class Solution {
public:
    // 最长公共子序列长度
    int lengthofLCSE(string &str1, string &str2) {
        if(str1.empty() || str2.empty()) return 0;
        vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
        for (int i = 1; i <= str1.size(); ++i) {
            for (int j = 1; j <= str2.size(); ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
        }
        return dp.back().back();
    }

    // 返回最长公共子序列
    string longestCommonSubSequence(string &str1, string &str2) {
        if(str1.empty() || str2.empty()) return "";
        vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
        for (int i = 1; i <= str1.size(); ++i) {
            for (int j = 1; j <= str2.size(); ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
        }

        string ret(dp.back().back(),'c');
        int index = ret.size() -1;
        int m = str1.size(), n = str2.size();
        while (index >= 0){
            if (n > 0 && dp[m][n] == dp[m][n-1])
                n--;    // 说明str2[n-1]这个字符不在公共序列
            else if(m>0 && dp[m][n] == dp[m-1][n])
                m--;
            else{
                // 如果dp[m][n] > dp[m][n-1]和dp[m-1][n]
                // 说明之前计算dp[m][n]时选择了dp[m-1][n-1]+1, 说明str1[m-1] == str2[n-1]
                ret[index--] = str1[--m];
                --n;
            }
        }

        return ret;
    }
};

int main(){
    string str1 = "1A2C3D4B56", str2 = "B1D23CA45B64"; // 123456 or 12C4B6都是最长公共子序列
    Solution sol;
    cout << sol.longestCommonSubSequence(str1, str2) << endl;
}

