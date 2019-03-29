class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int i = 1;    // 正数序列，从1开始    慢指针
        int j = 2;    // 快指针
        int s;    // 当前和
        vector<vector<int>> ret;
        while(i<j){
            s = (i+j)*(j-i+1)/2;
            if (s<sum){
                ++j;
            }
            else if (s > sum){
                ++i;
            }
            else{
                vector<int> tmp;
                for(int k =i;k<=j;++k)
                    tmp.push_back(k);
                ret.push_back(tmp);
                ++j;
            }
        }
        return ret;
    }
};