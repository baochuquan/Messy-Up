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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return ;
        vector<TreeNode*> ans;
        helper(root, ans);
        int n = ans.size();
        for(int i = 0; i < n-1; i++){
            ans[i]->left  = NULL;
            ans[i]->right = ans[i+1];
        }
        ans[n-1]->left = NULL;
        ans[n-1]->right = NULL;
    }
    void helper(TreeNode* root, vector<TreeNode*>& ans){
        if(root == NULL)
            return;
        ans.push_back(root);
        helper(root->left, ans);
        helper(root->right, ans);
    }
};
