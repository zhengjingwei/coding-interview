#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:    // 字符的类别数是有限的
    int FirstNotRepeatingChar(string str) {
        if (str.empty())
            return 0;

        unsigned hash_table[256] = {0}; // 记录每个字符出现的次数

        for (int i = 0; i < str.length(); ++i) {
            ++hash_table[str[i]];
        }

        for (int i = 0; i <str.length() ; ++i) {
            if(hash_table[str[i]]==1)
                return i;
        }
        return -1;
    }
};


int main(int argc, char** argv) {

    Solution sol;
    cout<<sol.FirstNotRepeatingChar("12312")<<endl;
    return 0;

}

