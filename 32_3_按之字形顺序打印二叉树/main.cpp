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

///*
// * 【1】同上一题分层打印二叉树相似，区别在于用一个变量控制打印的方向，每一层遍历的时候还是用队列存储进行层次遍历，只有最后打印时判断是否需要翻转。
//缺点：偶数层打印时需要翻转当前序列
// */
//class Solution {
//public:
//    vector<vector<int> > Print(TreeNode* pRoot) {
//        vector<vector<int> > ret;
//        vector<int> tmp;
//
//        if(pRoot == nullptr)
//            return ret;
//
//        int toBePrinted = 1;    // 当前层还没打印节点数
//        int nextLevel = 0;      // 下一层需要打印节点数
//        bool flag = true;    // 下一层打印方向
//        queue<TreeNode *> q;
//        q.push(pRoot);
//        while (!q.empty()){
//            TreeNode *node = q.front();
//            if (node->left != nullptr){
//                nextLevel++;
//                q.push(node->left);
//            }
//
//            if(node->right != nullptr){
//                nextLevel++;
//                q.push(node->right);
//            }
//
//            tmp.push_back(node->val);
//            q.pop();
//            toBePrinted --;
//            if (toBePrinted == 0){
//                if(!flag)       // 如果当前层需要从右往左打印
//                    reverse(tmp.begin(),tmp.end());
//                ret.push_back(tmp);
//                tmp.clear();    // 重置当前层打印记录
//                flag = !flag;   // 打印方向翻转
//                toBePrinted = nextLevel;
//                nextLevel = 0;
//            }
//        }
//        return ret;
//    }
//};


/*
 * 【2】用两个栈交替存储不同层的节点
 */
class Solution {
public:
    vector<vector<int> > Print(TreeNode *pRoot) {
        vector<vector<int> > ret;

        if(pRoot == nullptr)
            return ret;

        vector<int> tmp;
        stack<TreeNode*> s[2];
        int current = 0;    // 当前栈号
        int next =1;        // 下一个栈号
        s[current].push(pRoot);

        while (!s[0].empty() || !s[1].empty()){
            TreeNode *node = s[current].top();

            if(current == 0){
                if(node->left!= nullptr)
                    s[next].push(node->left);
                if(node->right!= nullptr)
                    s[next].push(node->right);
            } else{
                if(node->right!= nullptr)
                    s[next].push(node->right);
                if(node->left!= nullptr)
                    s[next].push(node->left);
            }

            tmp.push_back(node->val);
            s[current].pop();
            if(s[current].empty()){
                current = 1-current;    // 当前栈空进入下一层
                next = 1-next;
                ret.push_back(tmp);
                tmp.clear();
            }
        }

        return  ret;
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

