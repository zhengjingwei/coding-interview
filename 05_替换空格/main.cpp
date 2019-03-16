#include <iostream>
#include <vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str == nullptr || length <=0)
            return;

        int newLen = 0;     // 原字符串长度
        int originLen = 0;  // 替换后字符串长度
        int spaceNum = 0;   // 空格总数
        int i = 0;
        while(str[i] != '\0'){
            ++originLen;
            if(str[i] == ' '){
                ++spaceNum;
            }
            ++i;
        }

        newLen = originLen + spaceNum * 2; // 每替换一个空格，增加2个字符空间

        if(newLen > length) return;

        char *p1 = str + originLen; // 原字符串末
        char *p2 = str + newLen;    // 替换后字符串末

        while(p1!=p2){
            if(*p1 !=' '){
                *p2 = *p1;
                --p1;
                --p2;
            } else{
                *(p2-2) = '%';
                *(p2-1) = '2';
                *(p2) = '0';
                --p1;
                p2 -= 3;
            }
        }
    }
};

int main(int argc, char** argv) {

    char str[50] = " I want to be happy ";
    Solution sol;
    cout<<str<<endl;
    sol.replaceSpace(str, 50);
    cout<<str<<endl;
    return 0;
}