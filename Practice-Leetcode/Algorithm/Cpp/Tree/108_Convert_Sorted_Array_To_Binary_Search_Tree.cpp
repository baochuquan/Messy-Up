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
        if(nums.size() == 0)
            return NULL;
        return helper(0, nums.size()-1, nums);
    }
    TreeNode* helper(int l, int r, vector<int>& nums){
        if(l > r)
            return NULL;
        int m = (l+r)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = helper(l, m-1, nums);
        root->right = helper(m+1, r, nums);
        return root;
    }
};
