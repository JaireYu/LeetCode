  
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
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        else{
            if(root->left == NULL&&root->right != NULL)
                return isValidBST(root->left)&&isValidBST(root->right)&&compare_right(root);
            else if(root->left != NULL&&root->right == NULL)
                return isValidBST(root->left)&&isValidBST(root->right)&&compare_left(root);
            else if(root->left&&root->right)
                return isValidBST(root->left)&&isValidBST(root->right)&&compare_right(root)&&compare_left(root);
            else
                return true; 
        }
    }
    bool compare_left(TreeNode* root){
        TreeNode* p = root->left;
        while(p->right!=NULL){
            p = p->right;
        }
        return root->val > p->val;
    }
    bool compare_right(TreeNode* root){
        TreeNode* p = root->right;
        while(p->left!=NULL){
            p = p->left;
        }
        return root->val < p->val;
    }
};