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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* helper(vector<int>& inorder, int s0, int e0, vector<int>& postorder, int s1, int e1){
        if(s0 > e0)
            return NULL;
        int pos;
        int target = postorder[e1];
        for(int i = s0; i <= e0; i++){
            if(target == inorder[i]){
                pos = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(target);
        root->left  = helper(inorder, s0, pos-1, postorder, s1, e1-e0+pos-1);
        root->right = helper(inorder, pos+1, e0, postorder, e1-e0+pos, e1-1);
        return root;
    }
};
