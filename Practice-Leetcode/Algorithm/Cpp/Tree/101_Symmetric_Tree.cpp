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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* lt, TreeNode* rt){
        if(lt == NULL && rt == NULL)
            return true;
        if(lt == NULL || rt == NULL)
            return false;
        return lt->val == rt->val && helper(lt->left, rt->right) && helper(lt->right, rt->left);
    }
};
