tion for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        if(root == NULL)
            return res;
        helper(root, sum, 0, res, path);
        return res;

    }
    void helper(TreeNode* root, int sum, int cursum, vector<vector<int>>& res, vector<int> path){
        if(root == NULL)
            return ;

        path.push_back(root->val);
        if(root->left == NULL & root->right == NULL){
            if(sum == cursum + root->val){
                res.push_back(path);
            }
            return ;
        }
        helper(root->left, sum, cursum+root->val, res, path);
        helper(root->right, sum, cursum+root->val, res, path);
    }
};
