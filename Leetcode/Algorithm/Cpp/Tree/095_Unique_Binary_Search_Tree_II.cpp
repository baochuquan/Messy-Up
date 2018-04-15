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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        vector<int> num;
        if(n <= 0)
            return ans;
        for(int i = 1; i <= n; i++){
            num.push_back(i);
        }
        ans = helper(num, 0, n-1);
        return ans;
    }

    vector<TreeNode*> helper(vector<int>& num, int L, int R){
        vector<TreeNode*> ans;
        if(L > R){
            ans.push_back(NULL);
            return ans;
        }
        for(int i = L; i <= R; i++){
            vector<TreeNode*> leftList  = helper(num, L, i-1);
            vector<TreeNode*> rightList = helper(num, i+1, R);
            for(int x = 0; x < leftList.size(); x++){
                for(int y = 0; y < rightList.size(); y++){
                    TreeNode* root = new TreeNode(num[i]);
                    root->left = leftList[x];
                    root->right = rightList[y];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
