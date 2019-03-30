class Solution {
public:
    int Sum_Solution(int n) {
        int ret = n;
        // 利用前一个判断短路；当n=0时，不进行后一个判断的计算，作为递归终止
        ret && (ret += Sum_Solution(n-1));
        return ret;
    }
};