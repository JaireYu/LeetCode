/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) { 
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(root == NULL) return res;
       
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int size = q.size();
            while(size!=0){
                TreeNode* p = q.front();
                temp.push_back(p->val);
                if(p->left!=NULL) q.push(p->left);
                if(p->right!=NULL) q.push(p->right);
                q.pop();
                size --;
            }
            if(!temp.empty()){
                res.push_back(temp);
            }
        }
        return res;
    }
};