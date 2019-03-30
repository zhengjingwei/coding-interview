class Solution {
public:
    // 如果空缺总数小于等于0的个数，则数组连续
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() != 5)
            return false;

        int len = numbers.size();
        bool isCont = true;

        sort(numbers.begin(),numbers.end());    

        int index = 0;  
        while(numbers[index]==0) ++index;    // 统计0的个数

        // 从第2个非零项开始
        for (int i = index+1; i < len; ++i) {
            // 如果有非零重复项则不可能连续
            if (numbers[i] == numbers[i-1])
                return false;
            // 连续项
            if (numbers[i]- numbers[i-1] ==1){
                continue;
            }
            // 不连续但是有0可替代
            if (index>0 && numbers[i] - numbers[i-1] <= index+1)
                --index;
            else if (numbers[i] - numbers[i-1] > index +1)
                return false;
        }
        return isCont;
    }
};