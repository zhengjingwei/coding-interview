#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    int TreeDepth(TreeNode* pRoot){
        if (pRoot == nullptr)
            return 0;
        int maxLen = 0;
        maxLen = preOrderSearch(pRoot);
        return maxLen;
    }

    int preOrderSearch(TreeNode* pNode){
        if (pNode == nullptr)
            return 0;
        int left = preOrderSearch(pNode->left);
        int right = preOrderSearch(pNode->right);
        int len = left>right?left+1:right+1;    // 当前最大路径

        return len;

    }
};


int main(int argc, char** argv) {
    return 0;

}

