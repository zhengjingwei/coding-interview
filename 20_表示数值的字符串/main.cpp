#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string){
        if (string == nullptr)
            return false;

        bool numeric =  isSignedInt(&string);
        if(*string == '.'){
            string ++;
            // 用||的解释
            // 1. 小数点前可加整数，也可不加；
            // 2. 小数点后可以不带整数
            numeric = isUnsignedInt(&string) || numeric; // 注意isUnsignedInt需要放前面，才不会被numeric旁路
        }

        // 指数部分
        if(*string != '\0' && *string == 'E' || *string =='e'){
            string ++;
            // 用&&的解释
            // 1. 当e/E前没有数字时，整个字符串不能表示数字 如e1
            // 2. 当e/E后没有整数时，整个字符串不能表示数字，如12e、12e+5.4
            numeric = numeric && isSignedInt(&string);
        }

        numeric = numeric && (*string == '\0');
        return numeric;
    }

    // 判断带符号整数
    bool isSignedInt(char **str){
        if(**str == '+' || **str == '-')
            (*str) ++ ;

        return isUnsignedInt(str) ;
    }

    // 判断无符号整数
    bool isUnsignedInt(char **str){
        char *begin = *str;

        while(**str !='\0' && **str >='0' && **str <='9')
            (*str) ++;

        return *str > begin ;
    }
};

int main(){
    Solution sol;
//    cout<<sol.isNumeric("123")<< endl;          // 1
    cout<<sol.isNumeric("123.45e+6")<< endl;    // 1
    return 0;
}

