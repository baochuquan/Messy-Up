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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        int level = 1;
        helper(root, 1, ans);
        return ans;
    }
    void helper(TreeNode* root, int level, vector<vector<int> >& ans){
        if(root == NULL)
            return ;
        if(ans.size() < level){
            ans.push_back(vector<int>());
        }
        ans[level-1].push_back(root->val);
        helper(root->left, level+1, ans);
        helper(root->right, level+1, ans);
    }
};
