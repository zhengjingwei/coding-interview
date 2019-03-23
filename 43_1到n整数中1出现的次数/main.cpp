#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//class Solution {
//public:
//    int NumberOf1Between1AndN_Solution(int n)
//    {
//        int ret = 0;
//        for(int i = 1;i<= n;++i){
//            ret += NumberOf1(i);
//        }
//        return ret;
//    }
//
//    int NumberOf1(int n){
//        int num = 0;
//        while(n>0){
//            if (n%10 == 1)
//                ++ num;
//            n /= 10;
//        }
//        return num;
//    }
//};

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n){
        if (n <=0)
            return 0;
        char str[50];
        sprintf(str, "%d", n);  // 将数字转为中字符串便于处理
        return NumberOf1Core(str);
    }

    // 递归
    int NumberOf1Core(const char * str){
        if(!str || *str <'0' || *str > '9' || *str == '\0')
            return 0;

        int len = strlen(str);
        int first = *str - '0'; // 首位数字

        // 只剩个位的情况
        if (len == 1 && first >0) // 剩最后一个大于0
            return 1;
        if (len == 1 && first ==0)  // 剩最后一位为0
            return 0;

        int numOf1First = 0; // 首位为1的数目
        if (first >1){
            numOf1First = PowerBase10(len -1); // 以2345为例 首位为1有1000个

        } else if (first==1){   // 首位为1
            numOf1First = atoi(str + 1) + 1; // 以1234为例，首位为1有234+1=235个
        }

        // 以2345为例，是346~2345 除第一位外1的数目 2 * 3 * 10^2
        int numOf1Others  = first*(len-1)* PowerBase10(len-2);

        // 以2345为例，是1~345中1的数目
        int numof1Remain = NumberOf1Core(str+1);
        return numOf1First + numOf1Others + numof1Remain;
    }

    int PowerBase10(unsigned int n){
        int ret = 1;
        while (n--){
            ret *= 10;
        }
        return ret;
    }
};


int main(int argc, char** argv) {

    Solution sol;
    int a = 10000;
    cout << sol.NumberOf1Between1AndN_Solution(a) << endl;
    return 0;
}

