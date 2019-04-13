/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (!root)
            return vector<int> ();
        queue<TreeNode*> q;
        vector<int> ret;
        TreeNode *tmp;
        TreeNode *p = root;
        q.push(p);
        while(!q.empty()){
            p = q.front();
            if (p->left != nullptr){
                q.push(p->left);
            }
            if(p->right != nullptr){
                q.push(p->right);
            }
            tmp = q.front();    
            ret.push_back(tmp->val);
            q.pop();            // 头部出队
        }
        return ret;
    }
};