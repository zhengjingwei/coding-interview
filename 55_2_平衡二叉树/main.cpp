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

// 判断时检查树的深度；每次都检查
//class Solution {
//public:
//    // 返回值：树的深度
//    bool IsBalanced_Solution(TreeNode* pRoot){
//        if (pRoot == nullptr)
//            return true;
//        int left = TreeDepth(pRoot->left);    //
//        int right = TreeDepth(pRoot->right);
//        if (left - right > 1 || left - right < -1)
//            return false;
//        return true;
//    }
//
//    int TreeDepth(TreeNode* pRoot){
//        if (pRoot == nullptr)
//            return 0;
//
//        int left = TreeDepth(pRoot->left);
//        int right = TreeDepth(pRoot->right);
//        return left>right?left+1:right+1;
//    }
//};


class Solution {
public:
    // 返回值：树的深度
    bool IsBalanced_Solution(TreeNode* pRoot){
        if (pRoot == nullptr)
            return true;
        return TreeDepth(pRoot)!=-1;
    }

    // 返回值：
    // -1：子树不平衡
    // >0：子树深度
    int TreeDepth(TreeNode* pRoot){
        if (pRoot == nullptr)
            return 0;

        int left = TreeDepth(pRoot->left);
        if(left==-1)
            return -1;
        int right = TreeDepth(pRoot->right);
        if(right ==-1)
            return -1;
        if(left-right > 1 || left - right <-1)
            return -1;
        return left>right ? left+1:right+1;
    }
};

int main(int argc, char** argv) {
    return 0;

}

