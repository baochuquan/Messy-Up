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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int ln = helper(root->left, 0);
        int rn = helper(root->right, 0);
        return abs(ln-rn)<2 && isBalanced(root->left) && isBalanced(root->right);
    }
    int helper(TreeNode* root, int level){
        if(root == NULL)
            return level;
        int ln = helper(root->left, level+1);
        int rn = helper(root->right, level+1);
        return max(ln, rn);
    }
};
