/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> assi;
        left_push(root, assi);
        TreeNode* x = assi.top();
        assi.pop();
        res.push_back(x->val);
        x=x->right;
        left_push(x, assi);
        while(!assi.empty()){
            
            x = assi.top();
            assi.pop();
            res.push_back(x->val);
            x=x->right;
            left_push(x, assi);
        }
        return res;
    }
    void left_push(TreeNode* x, stack<TreeNode*>& assi){
        while(x!=NULL){
            assi.push(x);
            x = x->left;
        }
    }
    
    
};