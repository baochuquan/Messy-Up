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
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
    void helper(TreeNode* root){
        if(root == NULL)
            return ;
        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);
    }
};
