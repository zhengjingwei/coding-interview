#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 层序遍历二叉树
void seqOrder(TreeNode *root){
//    vector<int> ret;
    if(root == nullptr) return;
    queue<TreeNode*> q;
    TreeNode *node;
    q.push(root);
    while(!q.empty()){
        node = q.front();
        q.pop();
        cout<<node->val<<" ";
//        ret.push_back(node->val);
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return;
}

// 分层打印二叉树
void printTree(TreeNode *root){
    if(root == nullptr) return;
    queue<TreeNode*> q;
    TreeNode *node;
    int nodesToPrint = 1;   // 当前层节点总数
    int nextLayerNodes = 0; // 下一层节点总数
    int cnt = 0;            // 当前层已打印节点数
    q.push(root);
    while(!q.empty()){
        cnt = 0;
        nextLayerNodes = 0;
        while (cnt < nodesToPrint){
            node = q.front();
            q.pop();
            cout<<node->val<<" ";
            ++cnt;
            if(node->left) {
                q.push(node->left);
                ++nextLayerNodes;

            }
            if(node->right) {
                q.push(node->right);
                ++nextLayerNodes;
            }
        }
        cout<<endl;
        nodesToPrint = nextLayerNodes;
    }
}


// 先序遍历二叉树（递归）
void preOrder(TreeNode *root){
    if(root == nullptr) return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历二叉树（递归）
void inOrder(TreeNode *root){
    if(root == nullptr) return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

// 后序遍历二叉树（递归）
void posOrder(TreeNode *root){
    if(root == nullptr) return;
    posOrder(root->left);
    posOrder(root->right);
    cout<<root->val<<" ";
}

// 先序遍历（非递归）
void preOrderII(TreeNode *root){
    if(root == nullptr) return;
    stack<TreeNode*> s;
    while (root || !s.empty()){
        cout<<root->val<<" ";
        if(root->right) // 右子节点压栈
            s.push(root->right);
        if(root->left)  // 沿着左子节点遍历
            root = root->left;
        else{
            // 没有左子节点，弹栈
            if(!s.empty()){
                root = s.top();
                s.pop();
            }
            else return;    // 最后一个节点访问完
        }
    }
}

// 先序遍历（非递归）方法2
void preOrderIII(TreeNode *root){
    if(root == nullptr) return;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()){
        root = s.top();
        s.pop();
        cout<<root->val<<" ";
        if(root->right)
            s.push(root->right);
        if(root->left)
            s.push(root->left);
    }
}

// 中序遍历（非递归）
void inOrderII(TreeNode *root){
    if(root == nullptr) return;
    stack<TreeNode*> s;
    // 右子树为空，栈也为空时结束遍历
    while (root || !s.empty()){
        // 沿着左孩子将元素入栈
        while(root != nullptr){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        cout << root->val <<" ";
        root = root->right;
    } 
}

/*
 * 非递归后序遍历（方法1）
 * 用一个栈存储未访问的右子节点
 * 用一个变量last存储上一个访问的节点，用来判断右子节点是否访问过
 */
void posOrderII(TreeNode *root){
    if(root == nullptr) return;
    stack<TreeNode*> s;
    TreeNode *last = nullptr;   // 存储上一次访问的节点
    // 栈为空时结束遍历
    while (root!= nullptr || !s.empty()){
        while (root != nullptr){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        if(root->right == nullptr || root->right == last){  // 右子树已经访问过
            cout << root->val <<" ";
            s.pop();
            last = root;
            root = nullptr;
        }
        else
            root = root->right; // 右子树未访问，需要先访问有子树
    }
}

/*
 * 非递归后序遍历（方法2）
 * 将简洁的非递归先序遍历修改为 根->右->左 顺序遍历，然后将最后得到的递归序列翻转
 * 得到后序遍历 左->右->根
 */
void posOrderIII(TreeNode *root){
    vector<int> ret;
    if(!root) return ret;
    stack<TreeNode *> s;
    s.push(root);
    while ( !s.empty()){
        root = s.top();
        s.pop();
        ret.push_back(root->val);
        if (root->left)
            s.push(root->left);
        if (root->right)
            s.push(root->right);
    }
    for(int i = ret.size()-1; i>=0; --i)
        cout << ret[i] << endl;
}

int main(){
    /*
     *      1
     *     / \
     *    2   3
     *       / \
     *      4  5
     *     /
     *    6
     */
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(5);
    TreeNode *node5 = new TreeNode(6);
    root->left = node1,root->right = node2;
    node2->left = node3,node2->right = node4;
    node3->left = node5;

    cout<<"seqOrder\n"; // 层序遍历
    seqOrder(root);
    cout<<"\n\npreOrder\n"; // 先序遍历
    preOrder(root);
    cout<<"\n\npreOrderII\n"; // 先序遍历（非递归）
    preOrderII(root);
    cout<<"\n\npreOrderIII\n"; // 先序遍历（非递归）
    preOrderIII(root);
    cout<<"\n\ninOrder\n"; // 中序遍历
    inOrder(root);
    cout<<"\n\ninOrderII\n"; // 中序遍历（非递归）
    inOrderII(root);
    cout<<"\n\nposOrder\n"; // 后序遍历
    posOrder(root);
    cout<<"\n\nposOrderII\n"; // 后序遍历（非递归）
    posOrderII(root);
    cout<<"\n\nprintTree\n"; // 分层打印
    printTree(root);
    return 0;
}

