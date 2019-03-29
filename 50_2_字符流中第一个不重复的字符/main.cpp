#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution():index(-1){
        for (int i = 0; i < 256; ++i) {
            hash_table[i] = -1;
        }
    }

    //Insert one char from stringstream
    void Insert(char ch)
    {
        if(hash_table[ch] == -1){
            hash_table[ch] = ++index;   // 表示出现的位置
        }
        else if(hash_table[ch] >= 0){
            hash_table[ch] = -2;        // 标志为重复数字
        }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch = '#';
        int index_first = numeric_limits<int>::max(); // int的最大值
        for (int i = 0; i < 256; ++i) {
            if(hash_table[i] >= 0 && hash_table[i] < index_first){
                index_first = hash_table[i];
                ch = (char)i;               // 取对应字符
            }
        }
        return ch;

    }

private:
    // hash_table[i] >= 0 表示该字符首次出现
    // hash_table[i] = -1 表示该字符未出现
    // hash_table[i] = -2 表示该字符重复出现
    int hash_table[256]; // 出现的位置
    int index = -1;
};


int main(int argc, char** argv) {

    Solution sol;
    sol.Insert('a');
    sol.Insert('b');
    sol.Insert('b');
    cout<<sol.FirstAppearingOnce()<<endl;
    return 0;

}

