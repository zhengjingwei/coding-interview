#include <iostream>
#include <vector>
#include <random>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;

        // 二分查找缩小范围 O(logN)
        int index1 = 0;
        int index2 = rotateArray.size()-1;
        int mid;

        if(rotateArray[index1] < rotateArray[index2] && rotateArray[index1] < rotateArray[index1+1])
            return rotateArray[0]; // 第一个就是最小值

        while (index1 < index2){
            if(index2 - index1 == 1)
                return rotateArray[index2];

            mid = (index1 + index2) / 2;
            if(rotateArray[mid] < rotateArray[index1])
                index2 = mid;
            else if(rotateArray[mid] > rotateArray[index2])
                index1 = mid;
            else{
                int ret = rotateArray[index1];
                // 当区间头尾和中间的数字三个相同时，无法判断属于前面还是后面，顺序遍历
                for (int i = index1+1; i <=index2 ; ++i) {
                    if(rotateArray[i] <ret)
                        ret = rotateArray[i];
                }
                return ret;
            }
        }
        return rotateArray[index2];
    }
};

int main(int argc, char** argv) {
//    vector<int> arr = {4,5,6,6,7,1,2,3,3};
//    vector<int> arr = {1,1,1,0,1};
    vector<int> arr = {1,0,1,1,1};
    Solution sol;
    cout<<sol.minNumberInRotateArray(arr)<<endl;
//    cout<<arr.back()<<endl;
    return 0;
}