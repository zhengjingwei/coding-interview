#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//// 全排列 时间复杂度O（n!）
//class Solution {
//public:
//    string PrintMinNumber(vector<int> numbers) {
//        if (numbers.empty())
//            return "";
//        if (numbers.size() == 1)
//            return to_string(numbers[0]);
//
//        vector<string> ret; // 全排列
//        Permutation(numbers, 0, ret);
//
//        string minNumber = ret[0];  // 遍历全排列找最小
//        for (int i = 1; i < ret.size(); ++i) {
//            if (ret[i] < minNumber)
//                minNumber = ret[i];
//        }
//        return minNumber;
//
//    }
//    void Permutation(vector<int> &numbers, int index, vector<string> &ret){
//        if (index >= numbers.size()){
//            string s;
//            for (int i = 0; i < numbers.size(); ++i) {
//                s += to_string(numbers[i]);
//            }
//            ret.push_back(s);
//            return;
//        }
//
//        for (int i = index; i < numbers.size(); ++i) {
//            if (numbers[i] == numbers[index] && i!= index)  // 排除重复
//                continue;
//
//            swap(numbers[i],numbers[index]);
//
//            Permutation(numbers, index + 1, ret);
//
//            swap(numbers[i],numbers[index]);
//        }
//    }
//};

// 定义排序规则，使用qsort快排进行排序，时间复杂度O（nlogn）
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if (numbers.empty())
            return "";

        sort(numbers.begin(),numbers.end(), cmp);
        string ret = "";
        for (int i = 0; i < numbers.size(); ++i) {
            ret.append(to_string(numbers[i]));
        }
        return ret;

    }

    static bool cmp(int a, int b){
        string ab = to_string(a) + to_string(b);    //  to_string() 可以将int 转化为string
        string ba = to_string(b) + to_string(a);

        return ab < ba;
    }
};


int main(int argc, char** argv) {

    Solution sol;
    vector<int> num = {3,5,1,4,2};
    cout<<sol.PrintMinNumber(num)<<endl;
    return 0;
}

