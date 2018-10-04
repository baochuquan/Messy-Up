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
    bool isValidBST(TreeNode* root) {
        vector<int> sortedArr;
        helper(root, sortedArr);
        for(int i = 1; i < sortedArr.size(); i++){
            if(sortedArr[i] > sortedArr[i-1])
                continue;
            else
                return false;
        }
        return true;
    }
    void helper(TreeNode* root, vector<int>& sortedArr){
        if(root == NULL)
            return ;
        helper(root->left, sortedArr);
        sortedArr.push_back(root->val);
        helper(root->right, sortedArr);
    }

};
