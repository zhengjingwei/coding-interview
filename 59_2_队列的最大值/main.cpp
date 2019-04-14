#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void push_back(int num) {
        while (!maxNums.empty() && num >= maxNums.back())
            maxNums.pop_back();
        maxNums.push_back(num);
        data.push_back(num);
    }

    int pop_front() {
        if (data.empty())
            throw ("queue is empty");
        if(data.front() == maxNums.front())
            maxNums.pop_front();
        data.pop_front();
    }

    int max(){
        if (maxNums.empty())
            throw ("queue is empty");
        return maxNums.front();
    }

private:
    deque<int> data;
    deque<int> maxNums;
};



int main(){
    Solution sol;
    sol.push_back(3);
    sol.push_back(2);
    cout<<sol.max()<<endl;  // 3
    sol.pop_front();
    cout<<sol.max()<<endl;  // 2
    sol.push_back(4);
    cout<<sol.max()<<endl;  // 4
    return 0;
}

