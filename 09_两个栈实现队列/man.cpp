#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int ret = stack2.top();
        stack2.pop();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


int main(int argc, char** argv) {

    Solution sol;
    sol.push(1);
    sol.push(2);
    sol.push(3);
    cout<<sol.pop()<<endl;
    cout<<sol.pop()<<endl;
    sol.push(4);
    cout<<sol.pop()<<endl;

    return 0;
}