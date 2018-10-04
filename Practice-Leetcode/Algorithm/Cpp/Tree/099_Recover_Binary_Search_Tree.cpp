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
    void recoverTree(TreeNode* root) {
        if(root == NULL)
            return ;
        vector<TreeNode*> tree;
        helper(root, tree);
        int count = 0;
        int idx1, idx2;
        for(int i = 1; i < tree.size(); i++){
            if(count == 0 && tree[i]->val < tree[i-1]->val){
                count++;
                idx1 = i-1;
            } else if(count == 1 && tree[i]->val < tree[i-1]->val){
                count++;
                idx2 = i;
            }
        }
        if(count == 2){
            int tmp = tree[idx1]->val;
            tree[idx1]->val = tree[idx2]->val;
            tree[idx2]->val = tmp;
        }
        if(count == 1){
            int tmp = tree[idx1]->val;
            tree[idx1]->val = tree[idx1+1]->val;
            tree[idx1+1]->val = tmp;
        }
    }
    void helper(TreeNode* root, vector<TreeNode*>& tree){
        if(root == NULL)
            return ;
        helper(root->left, tree);
        tree.push_back(root);
        helper(root->right, tree);
    }
};
