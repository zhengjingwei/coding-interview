#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//// 哈希表存储某个数出现的次数 hash查询时间复杂度O（1）;总时间复杂度O（n）
//class Solution {
//public:
//    int MoreThanHalfNum_Solution(vector<int> numbers) {
//        map<int, int> m;
//        for (int i = 0; i < numbers.size(); ++i) {
//            m[numbers[i]]+=1;
//            if(m[numbers[i]]>=numbers.size()/2)
//                return numbers[i];
//        }
//        return 0;
//    }
//};

//// 先排序，取中间的数，若这个数在数组中出现超过长度一半，则存在；否则不存在
//// 时间复杂度O（nlogn）排序；空间复杂度O（1）
//class Solution {
//public:
//    int MoreThanHalfNum_Solution(vector<int> numbers) {
//        sort(numbers.begin(),numbers.end());
//        int key = numbers[numbers.size()/2];
//        int count = 0;
//        for (int i = 0; i < numbers.size(); ++i) {
//            if(key == numbers[i])
//                ++ count;
//        }
//        if (count>numbers.size()/2)
//            return key;
//        return 0;
//    }
//};

// 基于partiton函数 O(n)
// 如果存在：该数出现次数超过一半，排序第2/n个元素是该元素；即为中位数
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if(len==0)
            return 0;
        if(len==1)
            return numbers[0];
        int begin = 0;
        int end = len -1;
        int index = Partition(numbers, begin, end);
        // 寻找中位数
        while (index!=numbers.size()/2){
            if (index < len/2){
                begin = index +1;
                index = Partition(numbers,begin+1,end);
            }
            else{
                end = index -1;
                index = Partition(numbers,begin,end);
            }
        }

        // 遍历一遍统计该元素
        int count = 0;
        int key = numbers[index];
        for (int i = 0; i < len; ++i) {
            if(numbers[i] == key)
                ++ count;
        }
        if(count>len/2)
            return key;
        return 0;
    }

    int Partition(vector<int> &numbers, int begin, int end){
        if(begin >= end)
            return begin;

        int key = numbers[begin];   // 首元素作为基准值

        while (begin<end){
            while (begin<end && numbers[end] >= key)
                -- end;
            numbers[begin] = numbers[end];
            while (begin<end && numbers[begin] <= key)
                ++ begin;
            numbers[end] = numbers[begin];
        }
        numbers[begin] = key;
        return begin;
    }
};


int main(int argc, char** argv) {

    Solution sol;
    vector<int> a = {2,2,1,2,3};
    cout << sol.MoreThanHalfNum_Solution(a) << endl;
    return 0;
}

