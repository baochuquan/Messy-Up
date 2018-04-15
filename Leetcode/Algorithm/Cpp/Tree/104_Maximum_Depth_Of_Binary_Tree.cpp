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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int dep = INT_MIN;
        helper(root, 1, dep);
        return dep;
    }
    void helper(TreeNode* root, int level, int& dep){
        if(root == NULL)
            return ;
        if(root->left == NULL && root->right == NULL){
            dep = dep < level ? level : dep;
            return ;
        }
        helper(root->left, level+1, dep);
        helper(root->right, level+1, dep);
    }
};
