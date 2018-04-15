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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder, int s0, int e0, vector<int>& inorder, int s1, int e1){
        if(s1 > e1)
            return NULL;
        int target = preorder[s0];
        int pos;
        for(int i = s1; i <= e1; i++){
            if(target == inorder[i]){
                pos = i;
                break;
            }
        }

        TreeNode* root = new TreeNode(target);
        root->left  = helper(preorder, s0+1, s0+pos-s1-1, inorder, s1, pos-1);
        root->right = helper(preorder, s0+pos-s1+1, e0, inorder, pos+1, e1);
        return root;
    }
};
