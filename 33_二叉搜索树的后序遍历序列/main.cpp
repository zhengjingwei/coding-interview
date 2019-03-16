#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;

        // 中序遍历最后一个元素是根结点
        int root = sequence.back();
        int len = sequence.size();
        bool isTrue = true;
        int i = 0;

        // 左子树序列：：比根节点小的元素
        while(i<len && sequence[i]<root)
            i++;
        vector<int> leftSeq(sequence.begin(), sequence.begin() + i);
        bool left = leftSeq.empty()?true:VerifySquenceOfBST(leftSeq);

        // 右子树序列：比根节点大的元素
        int index = i;
        while(i<len && sequence[i] > root)
            i++;

        if (i < len-1)  // 如果有元素比根节点小的说明错误
            return  false;

        vector<int> rightSeq(sequence.begin()+index, sequence.end() -1);
        bool right = rightSeq.empty()?true:VerifySquenceOfBST(rightSeq);

        isTrue = left && right;
        return  isTrue;

    }
};

int main()
{
    vector<int> a = {4,8,6,12,16,14,10};
    vector<int> b = a;
    Solution sol;
    cout<<sol.VerifySquenceOfBST(a)<<endl;
    return 0;
}

