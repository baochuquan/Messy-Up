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
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;

        int sum = 0;
        helper(root, sum, 0);
        return sum;
    }
    void helper(TreeNode* root, int& sum, int curnum){
        if(root == NULL)
            return ;

        if(root->left == NULL && root->right == NULL){
            curnum = curnum*10 + root->val;
            sum += curnum;
            return ;
        }
        helper(root->left, sum, curnum*10+root->val);
        helper(root->right, sum, curnum*10+root->val);
    }
};
