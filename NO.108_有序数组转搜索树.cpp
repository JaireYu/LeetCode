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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        int n = nums.size();
        if(n == 0)
            return NULL;
		Bitree(root, 0, n-1, nums);
		return root;
	}
	void Bitree(TreeNode* &root, const int& low, const int& high, const vector<int>& nums) {
		int i = (low + high) / 2;
		root = new TreeNode(1);
		root->val = nums[i];
		if (i == low) 
			root->left = NULL;
		else
			Bitree(root->left, low, i - 1, nums);
		if (i == high) 
			root->right = NULL;
		else
			Bitree(root->right, i + 1, high, nums);
	}
};