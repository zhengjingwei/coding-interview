#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 *
 * 时间复杂度O(n) 空间复杂度O(1)
 */
class Solution {
public:
    int longestSubrstringWithoutDuplication(string str){
        if(str.empty()) return 0;

        int maxLen = 0;             // 无重复字符子串最大长度
        int currentLen = 0;         // 以当前位置字符结尾的无重复字符子串最大长度
        int *pos = new int[26];
        for (int i = 0; i < 26; ++i) {
            pos[i] = -1;    // 该字符上次被访问的位置 -1表示未被访问过
        }

        for (int i = 0; i < str.size(); ++i) {
            int preIndex = pos[str[i] - '0'];

            if(preIndex < 0 || i - preIndex > currentLen)
                ++currentLen;   // 当前字符从未被访问过or与上一次被访问的距离超过以前一个字符结尾的最大长度
            else
                currentLen = i - preIndex;

            if(currentLen>maxLen)   // 如果当前字符结尾子串更长则更新最大长度
                maxLen = currentLen;
            pos[str[i] - '0'] = i;
        }

        if(currentLen>maxLen)
            maxLen = currentLen;

        delete[] pos;
        return maxLen;
    }
};

int main(){
    string s = "arabcacfr";
    Solution sol;
    int ret = sol.longestSubrstringWithoutDuplication(s);
    cout << ret << endl;
    return 0;
}

