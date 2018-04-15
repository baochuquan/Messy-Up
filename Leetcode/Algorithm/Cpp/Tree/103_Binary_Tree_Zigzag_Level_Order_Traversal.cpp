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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        int level = 1;
        bool direct = true;
        helper(root, level, direct, ans);
        return ans;
    }
    void helper(TreeNode* root, int level, bool direct, vector<vector<int> >& ans){
        if(root == NULL)
            return ;
        if(level > ans.size())
            ans.push_back(vector<int>());

        if(direct){
            ans[level-1].push_back(root->val);
        } else {
            ans[level-1].insert(ans[level-1].begin(), root->val);
        }
        helper(root->left, level+1, !direct, ans);
        helper(root->right, level+1, !direct, ans);

    }
};
