#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 迭代
 * O(log N * log N)
 */
class SolutionI {
public:
    TreeNode* getLastNode(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return root;
        int height = 0;     // 树高度
        TreeNode *node = root;
        while (node){
            node = node->left;
            ++ height;
        }

        TreeNode *last = root;  // 当前比较的左子树和右子树的根节点
        while (last->left != nullptr){  // 指向叶子节点时退出
            int lh = --height;
            int rh = 0;
            node = last->right;
            while (node){
                ++ rh;
                node = node->left;
            }
            if(lh > rh)
                last = last->left;
            else
                last = last->right;
        }

        return last;
    }
};


/*
 * 递归
 * 求子树高度：如果当前根节点为叶子节点，则返回
 * 如果左子树高度>右子树高度，则在左子树递归
 * 否则在右子树递归
 * 时间复杂度O(logN * logN) （求高度 * 遍历层数）
 */
class Solution {
public:
    TreeNode* getLastNode(TreeNode* root) {
        if(!root || root->left == nullptr)
            return root;
        int leftHeight = 0;     // 左子树高度
        TreeNode *node = root->left;
        while (node){
            node = node->left;
            ++ leftHeight;
        }

        int rightHeight = 0;    // 右子树高度
        node = root->right;
        while(node){
            node = node->left;
            ++ rightHeight;
        }

        if(leftHeight > rightHeight)
            return getLastNode(root->left);
        else
            return getLastNode(root->right);
    }
};