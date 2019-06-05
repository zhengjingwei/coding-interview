#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getTranslationCount(int number){
        if(number < 0)
            return 0;
        string numberInString  = to_string(number);
        return getTranslationCount(numberInString);
    }

private:
    int getTranslationCount(const string &number) {
        int len = number.size();
        int *counts = new int[len]; // 当前位置的计数
        int count = 0;

        for (int i = 0; i < len; ++i) {
            // 设置初始值
            if (i==0)
                count = 1;
            else
                count = counts[i-1];

            if (i>0 ){
                int digit1 = number[i-1] - '0';
                int digit2 = number[i] - '0';
                int convertedNum = digit1 * 10 +digit2;

                // 该两位数有效
                if (convertedNum <= 25 && convertedNum>=10){
                    if(i>1)
                        count += counts[i-2];
                    else
                        count += 1;
                }
            }

            counts[i] = count;
        }

        count = counts[len-1];
        delete[](counts);
        return count;
    }
};

int main(){
    int num = 12258;
    Solution sol;
    cout <<sol.getTranslationCount(num) << endl;
    return 0;
}

