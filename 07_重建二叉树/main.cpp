#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    TreeNode * construct(vector<int> pre, vector<int> vin){
        if(pre.empty() || vin.empty()){
            return nullptr;
        }
        return reConstructBinaryTree(pre,vin); // 递归求解
    }

    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int rootVal = pre[0];
        int rootIndex = 0;
        int len = pre.size();
        TreeNode *root = new TreeNode(rootVal);

        for(int i = 0;i<vin.size(); ++i){
            if(vin[i] == rootVal){
                rootIndex = i;
                break;
            }

        }
        // 构建左子树
        vector<int> vinLeft(vin.begin(), vin.begin()+ rootIndex);
        vector<int> preLeft(pre.begin()+1, pre.begin()+ rootIndex + 1 );
        root->left = construct(preLeft,vinLeft);

        // 构建右子树
        int lenRight = len - rootIndex -1;
        vector<int> vinRight(vin.end() - lenRight, vin.end()); // 用end求子串 避免越界
        vector<int> preRight(pre.end() - lenRight, pre.end());
        root->right = construct(preRight,vinRight);

        return root;
    }
};

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


int main(int argc, char** argv) {

//    vector<int> prevOrder = {1,2,4,7,3,5,6,8};
//    vector<int> inOrder = {4,7,2,1,5,3,8,6};
    vector<int> prevOrder = {1,2,3,4};
    vector<int> inOrder = {1,2,3,4};


    Solution sol;
    TreeNode* bTree = sol.reConstructBinaryTree(prevOrder, inOrder);
    bfsTree(bTree);

    TreeNode* test = new TreeNode(0);
    test->left = new TreeNode(1);
    test->right = new TreeNode(2);
    test->left->left = new TreeNode(3);
    test->right->right = new TreeNode(4);
    test->right->left = new TreeNode(5);

    
    return 0;
}