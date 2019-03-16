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


// 将数组转化为二叉树 输入-1表示空节点
TreeNode* CreateTree(vector<int> v){
    if(v.empty())
        return nullptr;
    TreeNode *root = new TreeNode(v[0]);
    TreeNode *p = root;
    queue<TreeNode *> q;
    q.push(p);
    int i = 1;

    while(!q.empty()){
        p = q.front();
        if (i  <v.size() && v[i] > 0){
            p->left = new TreeNode(v[i]);
            q.push(p->left);
        }
        ++i;

        if (i  <v.size() && v[i] > 0){
            p->right = new TreeNode(v[i]);
            q.push(p->right);

        }
        ++i;
        q.pop();
    }
    return root;
}

// 层次遍历二叉树
void PrintTree(TreeNode *root){
    if(root== nullptr)
        return;

    TreeNode *p = root;
    queue<TreeNode*> q;
    q.push(p);

    while(!q.empty()){
        p = q.front();
        if(p->left!= nullptr)
            q.push(p->left);
        if(p->right!= nullptr)
            q.push(p->right);

        cout<<p->val<<" ";
        q.pop();
    }
}

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree){
        if (pRootOfTree== nullptr)
            return pRootOfTree;
        TreeNode* lastNodeInList = nullptr;         // 保存当前双向链表的尾节点
        ConvertNode(pRootOfTree, &lastNodeInList);  // 得到转换完后双向链表的尾节点
        TreeNode* pHeadofList = lastNodeInList;
        pHeadofList->right = nullptr;
        while(pHeadofList->left!= nullptr)
            pHeadofList = pHeadofList->left;

        return pHeadofList;
    }

    // 左子树的最右节点 -》根节点-》右子树最左节点
    // 二叉搜索树按中序遍历：从小到大
    void ConvertNode(TreeNode* root, TreeNode** lastNodeInList){
        if(root== nullptr)
            return;

        // 左子树转换
        ConvertNode(root->left,lastNodeInList);
        root->left = *lastNodeInList;   // 根的左指针指向排序完左子树最右节点
        if(*lastNodeInList != nullptr)
            (*lastNodeInList)->right = root;

        // 将根节点加入排序列表；并在右子树中递归
        *lastNodeInList = root;
        ConvertNode(root->right,lastNodeInList);
    }
};

void PrintBinaryList(TreeNode* pHead){
    while(pHead!= nullptr){
        cout<<pHead->val<<" ";
        pHead = pHead->right;
    }
}

int main()
{
    Solution sol;
    vector<int> a = {8,6,10,5,7,-1,11};
    TreeNode *root = CreateTree(a);
    PrintTree(root);
    cout<<"convert:"<<endl;
    TreeNode *convetList = sol.Convert(root);
    PrintBinaryList(convetList);
//    Test1();
    return 0;
}

