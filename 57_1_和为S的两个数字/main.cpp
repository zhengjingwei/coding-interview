class Solution {
public:
    // 双指针分别从头和尾向中间走；时间复杂度O（n）
    // 关键在于双指针的行走是单调的；左指针+1，和增加；右指针-1，和减小
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ret;
        if (array.size()<=1)
            return ret;
        
        int i = 0;
        int j = array.size() -1;
        int m=-1,n=-1;
        int prod = numeric_limits<int>::max();

        while(i<j){
            int s = array[i] + array[j];
            if(s < sum)
                ++i;    // 当前和小于sum；左指针+1
            else if (s>sum)
                --j;    // 当前和大于sum；右指针-1
            else{
                if ( array[i] * array[j]< prod){
                    m = i;
                    n = j;
                    prod = array[i] * array[j];
                }
                ++i;
                --j;
            }
        }
        
        if (m!=-1 && n!=-1){
            ret.push_back(array[m]);
            ret.push_back(array[n]);
        }
        return ret;
    }
};