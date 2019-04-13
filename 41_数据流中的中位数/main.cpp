class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int, vector<int>, less<int>> max;
public:
    void Insert(int num){
        if(max.empty() || num<= max.top())
            max.push(num);
        else
            min.push(num);
        // 保持最大堆数目不小于最小堆；并且相差最多为1
        if(max.size()== min.size() +2){
            min.push(max.top());
            max.pop();
        }
        if(max.size() +1 == min.size()){
            max.push(min.top());
            min.pop();
        }
    }

    double GetMedian(){
        if(min.size() == max.size())
            return (min.top() + max.top()) / 2.0;
        else
            return max.top();
    }
};