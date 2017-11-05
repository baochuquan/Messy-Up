class Solution {
    vector<int> ans;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
    void helper(TreeNode* root){
        if(root == NULL)
            return ;
        ans.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }
};
