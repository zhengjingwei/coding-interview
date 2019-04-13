/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == nullptr)
            return nullptr;

        // 如果有右子树：找右子树最左节点
        if (pNode->right!= nullptr){
            pNode = pNode->right;
            while (pNode->left!= nullptr)
                pNode = pNode->left;
            return pNode;
        }

        // 如果没有右子树；往上找父节点；得到某个是其父节点右子树的节点，返回该节点
        while(pNode->next!= nullptr){
            TreeLinkNode *pRoot = pNode->next;
            // 如果该节点是父节点的左孩子
            if(pRoot->left == pNode)
                return pRoot;
            pNode = pNode->next;
        }
        // 该节点为最后一个节点
        return nullptr;
    }
};