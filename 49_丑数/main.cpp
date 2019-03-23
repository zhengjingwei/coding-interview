#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 只考虑是丑数的数字
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <=0)
            return 0;
        int index2 = 0;    // 该数是乘以2大于目前最大丑数的数中最小的；其序号
        int index3 = 0;
        int index5 = 0;
        vector<int> num = {1};  // 1为最小的丑数
        for (int i=1; i< index;i++){
            int mul2 = num[index2] * 2; // 与2的乘积
            int mul3 = num[index3] * 3;
            int mul5 = num[index5] * 5;

            int tmp = min(min(mul2,mul3),mul5); // 找到乘积中最小的数加入数组
            if (tmp==mul2) ++index2;            // 并将其序号+1
            if (tmp== mul3) ++index3;
            if (tmp==mul5) ++index5;
            num.push_back(tmp);
        }
        return num[index-1];
    }
};


int main(int argc, char** argv) {

    Solution sol;
    int n = 8;
    cout<<sol.GetUglyNumber_Solution(n)<<endl;
    return 0;
}

