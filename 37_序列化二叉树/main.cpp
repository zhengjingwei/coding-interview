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
    char* Serialize(TreeNode *root) {

        if(root == nullptr){
            return "#";
        }

        string s = to_string(root->val);
        s.push_back(',');
        char *left = Serialize(root->left);
        char *right = Serialize(root->right);
        char *ret = new char[strlen(left) + strlen(right) + s.size()];
        strcpy(ret,s.c_str());
        strcat(ret,left);
        strcat(ret,right);
        return ret;
    }

    TreeNode* Deserialize(char *&str) {
        if (*str == '#'){
            str ++;
            return nullptr;
        }
        int num = 0;
        while (*str!=','){
            num = num * 10 + (*(str++) - '0');
        }
        str ++; // 跳过','
        TreeNode *root = new TreeNode(num);
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        return root;
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
    char *s = sol.Serialize(root);
    cout<<s<<endl;
    TreeNode *node = sol.Deserialize(s);
    bfsTree(node);
    return 0;
}

