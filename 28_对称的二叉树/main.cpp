/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymmetrical(pRoot,pRoot);
    }
    // 比较二叉树的先序遍历序列和对称先序遍历序列（根->右->左）
    // 相等：对称
    bool isSymmetrical(TreeNode* pRoot1, TreeNode *pRoot2){
        
        // 因为可能存在所有元素相等的情况；遍历序列考虑nullptr
        if(pRoot1 == nullptr && pRoot2 == nullptr)
            return true;
        
        // 一个空指针，另一个非空指针
        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        
        if (pRoot1->val != pRoot2->val )
            return false;
        
        return isSymmetrical(pRoot1->left,pRoot2->right) && 
            isSymmetrical(pRoot1->right,pRoot2->left) ;
        
    }

};