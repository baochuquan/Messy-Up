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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;

        return helper(root, sum, 0);
    }
    bool helper(TreeNode* root, int sum, int cursum){
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL){
            if(sum == cursum+root->val)
                return true;
        }
        return helper(root->left, sum, cursum+root->val) || helper(root->right, sum, cursum+root->val);
    }
};
