#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class ReturnType{
public:
    TreeNode *maxBSTRoot;   // 最大BST子树根节点
    int maxBSTSize;         // 最大BST子树节点数
    int min;                // 树节点最小值
    int max;                // 树节点最大值
    ReturnType(TreeNode* maxBSTRoot, int maxBSTSize, int min, int max ){
        this->maxBSTRoot = maxBSTRoot;
        this->maxBSTSize = maxBSTSize;
        this->min = min;
        this->max = max;
    }
};

/*
 * 时间复杂度O(n)
 * 空间复杂度O(1)
 */
class Morris {
public:
    vector<int> morris(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;

        TreeNode *mostRight = nullptr; // 当前节点左子树的最右节点
        while(root){
            ret.push_back(root->val);
            mostRight = root->left;
            // 如果当前节点有左子树
            if(mostRight){
                // 找到root左子树的最右节点
                while (mostRight->right && mostRight->right!=root)
                    mostRight = mostRight->right;
                // 如果mostRight的右指针指向空节点 则设置其指向root
                if(mostRight->right == nullptr){
                    mostRight->right = root;
                    root = root->left;      // root向左移动
                    continue;
                } else{
                    mostRight->right = nullptr;
                }
            }
            // root如果没有左子树，向右移动
            // 或者root左子树上最右节点是指向root的，root向右移动
            root = root->right;
        }

        return ret;
    }

    /*
     * Morris先序遍历
     * 对于只到达一次的节点（无左子树节点），root到达时直接打印
     * 对于可以到达两次的节点（有左子树节点），root第一次到达时打印，第二次到达时不打印
     */
    vector<int> morrisPre(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;

        TreeNode *mostRight = nullptr; // 当前节点左子树的最右节点
        while(root){
            mostRight = root->left;
            // 如果当前节点有左子树
            if(mostRight){
                // 找到root左子树的最右节点
                while (mostRight->right && mostRight->right!=root)
                    mostRight = mostRight->right;
                // 如果mostRight的右指针指向空节点 则设置其指向root
                if(mostRight->right == nullptr){
                    mostRight->right = root;
                    ret.push_back(root->val);
                    root = root->left;      // root向左移动
                    continue;
                } else{
                    mostRight->right = nullptr;
                }
            } else{
                ret.push_back(root->val);
            }

            // root如果没有左子树，向右移动
            // 或者root左子树上最右节点是指向root的，root向右移动
            root = root->right;
        }

        return ret;
    }


    /*
     * Morris中序遍历
     * 对于只到达一次的节点（无左子树节点），root到达时直接打印
     * 对于可以到达两次的节点（有左子树节点），root第一次到达时不打印，第二次到达时打印
     */
    vector<int> morrisMid(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;

        TreeNode *mostRight = nullptr; // 当前节点左子树的最右节点
        while(root){
            mostRight = root->left;
            // 如果当前节点有左子树
            if(mostRight){
                // 找到root左子树的最右节点
                while (mostRight->right && mostRight->right!=root)
                    mostRight = mostRight->right;
                // 如果mostRight的右指针指向空节点 则设置其指向root
                if(mostRight->right == nullptr){
                    mostRight->right = root;
                    root = root->left;      // root向左移动
                    continue;
                } else{
                    ret.push_back(root->val);
                    mostRight->right = nullptr;
                }
            } else{
                ret.push_back(root->val);
            }

            // root如果没有左子树，向右移动
            // 或者root左子树上最右节点是指向root的，root向右移动
            root = root->right;
        }

        return ret;
    }
};


int main(){
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);
    node4->left = node2, node4->right = node6;
    node2->left = node1, node2->right = node3;
    node6->left = node5, node6->right = node7;
    TreeNode *root = node4;
    Morris mo;
    vector<int> nums1 = mo.morris(root);
    for(auto v:nums1)
        cout <<v <<" ";
    cout <<endl;
    vector<int> nums2 = mo.morrisPre(root);
    for(auto v:nums2)
        cout <<v <<" ";
    cout <<endl;
    vector<int> nums3 = mo.morrisMid(root);
    for(auto v:nums3)
        cout <<v <<" ";
    return 0;
}