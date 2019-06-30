/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
		vector<int> nums;
		ListNode* q = head;
		TreeNode* root = NULL;
		while (q != NULL) {
			nums.push_back(q->val);
            q = q->next;
		}
		int n = nums.size();
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