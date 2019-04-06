#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern) {
        if(str == nullptr && pattern == nullptr)
            return true;
        return matchCore(str, pattern);
    }
    bool matchCore(char* str, char* pattern){
        if(*str == '\0' && *pattern == '\0')    //
            return true;
        if(*str != '\0' && *pattern == '\0')    //
            return false;

        if(*(pattern+1) == '*'){
            // 当前字符匹配
            if( *pattern == *str || (*pattern == '.' && *str!='\0')){
                return matchCore(str+1, pattern+2)    // str当前字符移动一个位置，*匹配一个字符，模式状态改变
                    || matchCore(str+1, pattern)      // str当前字符移动一个位置，*匹配一个字符，模式保持状态不变
                    || matchCore(str, pattern+2);     // 忽略*字符
            } else
                // 当前字符不匹配 忽略 *
                return matchCore(str, pattern+2);
        }

        // 逐个字符匹配
        if(*str == *pattern || (*pattern == '.' && *str!='\0'))
            return match(str+1,pattern+1);

        return false;
    }
};

void Test1(){
    Solution sol;
    char *str = "aaa";
    char *pat1 = "a.a";     // 1
    char *pat2 = "ab*ac*a"; // 1
    char *pat3 = "aa.a";    // 0
    char *pat4 = "ab*a";    // 0
    cout<<"== Test1 =="<<endl;
    cout<<sol.match(str,pat1)<<endl;
    cout<<sol.match(str,pat2)<<endl;
    cout<<sol.match(str,pat3)<<endl;
    cout<<sol.match(str,pat4)<<endl;
}

void Test2(){
    Solution sol;
    char *str1 = "";
    char *pat1 = "";
    char *str2 = "";
    char *pat2 = ".";
    char *pat3 = ".*";
    cout<<"== Test2 =="<<endl;
    cout<<sol.match(str1,pat1)<<endl; // 1
    cout<<sol.match(str2,pat2)<<endl; // 0
    cout<<sol.match(str2,pat3)<<endl; // 1
}

int main(int argc, char** argv) {
    Test1();
    Test2();
    return 0;
}

