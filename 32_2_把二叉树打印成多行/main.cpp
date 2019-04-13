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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > ret;
        vector<int> tmp;

        if(pRoot == nullptr)
            return ret;

        int toBePrinted = 1;    // 当前层还没打印节点数
        int nextLevel = 0;      // 下一层需要打印节点数
        queue<TreeNode *> q;
        q.push(pRoot);
        while (!q.empty()){
            TreeNode *node = q.front();

            if (node->left != nullptr){
                nextLevel++;
                q.push(node->left);
            }

            if(node->right != nullptr){
                nextLevel++;
                q.push(node->right);
            }

            tmp.push_back(node->val);
            q.pop();
            toBePrinted --;
            if (toBePrinted == 0){
                ret.push_back(tmp);
                tmp.clear();                // 重置当前层打印记录
                toBePrinted = nextLevel;
                nextLevel = 0;
            }
        }

        return ret;
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
    TreeNode * root = Test1();
    vector<vector<int>> ret = sol.Print(root);
    for (auto k:ret){
        for(auto v:k)
            cout<<v<<" ";
        cout<<endl;
    }
    return 0;
}

