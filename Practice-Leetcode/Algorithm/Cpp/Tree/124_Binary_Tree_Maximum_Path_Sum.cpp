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
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        int maxpath = INT_MIN;
        int rtol = helper(root, maxpath);
        return rtol > maxpath ? rtol : maxpath;
    }
    int helper(TreeNode* root, int &maxpath){
        if(root == NULL){
            return 0;
        }
        int left = helper(root->left, maxpath);
        int right = helper(root->right, maxpath);
        int cur = left + right + root->val;

        maxpath = maxpath > left+root->val ? maxpath : left+root->val;
        maxpath = maxpath > right+root->val ? maxpath : right+root->val;
        maxpath = maxpath > cur ? maxpath : cur;
        maxpath = maxpath > root->val ? maxpath : root->val;

        int rt = left > right ? left+root->val: right+root->val;
        rt = rt > root->val ? rt : root->val;
        return rt;
    }
};
