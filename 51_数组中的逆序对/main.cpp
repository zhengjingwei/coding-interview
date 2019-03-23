#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size() <= 1)
            return 0;
        int count = 0;
        vector<int> copy(data); // 初始化
        InversePairsCore(data, copy, 0, data.size()-1,count);
        return count;
    }

    // 归并
    void InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end, int &count){
        if(start>=end){
            return;
        }
        int mid = (start + end) /2;
        InversePairsCore(data,copy,start,mid,count);
        InversePairsCore(data,copy,mid+1,end,count);

        int copyIndex = end; // 将较大数字从后往前复制到辅助数组
        int i = mid;    // 前半段最后一个元素下标
        int j = end;    // 后半段最后一个元素下标
        while (i>=start && j>=mid+1) {
            if (data[j] < data[i]){     // 逆序
                count += j - mid;
                copy[copyIndex--] = data[i--];
            } else{
                copy[copyIndex--] = data[j--];
            }
        }

        while (i>=start)
            copy[copyIndex--] = data[i--];

        while (j>=mid+1)
            copy[copyIndex--] = data[j--];

        for (int k = start; k <= end; ++k)
            data[k] = copy[k];

    }
};


int main(int argc, char** argv) {

    Solution sol;
    vector<int> a = {7,5,4,6};
    cout<<sol.InversePairs(a)<<endl;
    return 0;

}

