#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())
            return 0;
        int flag = 1;
        int i =0;
        int num = 0;

        if (str[0] == '-'){
            flag = -1;
            ++i;
        } else if(str[0] == '+')
            ++i;

        for (; i < str.size(); ++i) {
            if(str[i]>'9' || str[i] < '0')
                return 0;
            int ch = str[i] - '0';


            // 判断是否上溢出或者下溢出
            if ((flag==1 && num > (numeric_limits<int>::max()-flag * ch)/10)
                || (flag==-1 && num< (numeric_limits<int>::min()-flag * ch)/10))
            {
                return 0;
            }

            num = num *10 + flag * ch;
        }
        return num;
    }
};


int main(int argc, char** argv) {
    Solution sol;
    string str1 = "123456666666666688888888888888888";
    string str2 = "-12345";
    string str3 = "a567";
    string str4 = "";
    cout<<sol.StrToInt(str1)<<endl;
    cout<<sol.StrToInt(str2)<<endl;
    cout<<sol.StrToInt(str3)<<endl;
    cout<<sol.StrToInt(str4)<<endl;

    return 0;
}

