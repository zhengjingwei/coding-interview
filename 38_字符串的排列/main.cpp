#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        if (str.empty())
            return vector<string>();
        if (str.size()==1)
            return vector<string> {str};

        vector<string> res;
        PermutationCore(str,0,res);

        // 按字典序排列
        sort(res.begin(),res.end());
        return res;

    }

    void PermutationCore(string str ,int begin, vector<string> &res) {
        if (begin >= str.size()){
            res.push_back(str);
            return;
        }

        for (int i = begin; i < str.size(); ++i) {
            // 如果出现重复元素；跳过
            if (str[begin] == str[i] && begin!=i){
                continue;
            }

            // 将首元素和后面元素交换
            char tmp = str[begin];
            str[begin] = str[i];
            str[i] = tmp;

            PermutationCore(str,begin+1,res);

            // 将交换恢复
            tmp = str[begin];
            str[begin] = str[i];
            str[i] = tmp;
        }
    }
};



int main(int argc, char** argv) {

    Solution sol;
//    vector<string> res = sol.Permutation("aa"); // 重复数字
    vector<string> res = sol.Permutation("abc");
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<endl;
    }

    return 0;
}

