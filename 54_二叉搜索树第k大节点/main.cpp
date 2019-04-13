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
    TreeNode* KthNode(TreeNode* pRoot, int k){
        if(pRoot == nullptr || k<1)
            return nullptr;
        return find(pRoot, k);
    }

    TreeNode *find(TreeNode* pRoot, int &k){
        if(pRoot == nullptr)
            return nullptr;

        TreeNode *left = find(pRoot->left,k);
        if(left!= nullptr){
            if(k==0)    // 是0直接返回
                return left;
            --k;
        }

        if(--k == 0)    // 注意这个地方要先减1再判断
            return pRoot;

        TreeNode *right = find(pRoot->right,k);
        if(right!= nullptr){
            if(k == 0)
                return right;
            --k;
        }
        return nullptr;
    }
};

TreeNode* Test1(){
    TreeNode* test = new TreeNode(0);
    test->left = new TreeNode(1);
    test->right = new TreeNode(2);
    test->left->left = new TreeNode(3);
    test->right->left = new TreeNode(4);
    test->right->right = new TreeNode(5);
    return test;
}

TreeNode* Test2(){
    TreeNode* test = new TreeNode(5);
    test->left = new TreeNode(3);
    test->right = new TreeNode(7);
    test->left->left = new TreeNode(2);
    test->left->right = new TreeNode(4);
    test->right->left = new TreeNode(6);
    test->right->right = new TreeNode(8);
    return test;
}

// 宽度优先遍历
void bfsTree(TreeNode* bt){
    if(bt == nullptr)
        return;
    queue<TreeNode *> nodes;
    nodes.push(bt);
    while (!nodes.empty()){
        TreeNode *node = nodes.front();
        cout<< node->val << ' ';
        nodes.pop();

        if(node->left != nullptr){
            nodes.push(node->left);
        }
        if(node->right != nullptr){
            nodes.push(node->right);
        }
    }
}


int main(){
    Solution sol;
    TreeNode *root = Test2();
    TreeNode *node = sol.KthNode(root,3);
    cout<<node->val<<endl;
    return 0;
}

