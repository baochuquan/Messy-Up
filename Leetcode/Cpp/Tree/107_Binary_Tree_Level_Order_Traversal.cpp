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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        vector<vector<int> > res;
        int level = 1;
        helper(root, level, ans);
        int n = ans.size();
        for(int i = 0; i < n; i++){
            res.push_back(ans[n-i-1]);
        }
        return res;
    }
    void helper(TreeNode* root, int level, vector<vector<int> >& ans){
        if(root == NULL)
            return ;
        if(level > ans.size()){
            ans.push_back(vector<int>());
        }
        ans[level-1].push_back(root->val);
        helper(root->left, level+1, ans);
        helper(root->right, level+1, ans);
    }
};
