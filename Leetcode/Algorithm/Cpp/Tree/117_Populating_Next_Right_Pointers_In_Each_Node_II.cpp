/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<vector<TreeLinkNode*> > ans;
        helper(root, 1, ans);
        int n = ans.size();
        for(int i = 0; i < n; i++){
            int m = ans[i].size();
            int j;
            for(j = 0; j < m-1; j++){
                ans[i][j]->next = ans[i][j+1];
            }
            ans[i][j]->next = NULL;
        }
    }
    void helper(TreeLinkNode* root, int level, vector<vector<TreeLinkNode*> >& ans){
        if(root == NULL)
            return ;
        if(level > ans.size()){
            ans.push_back(vector<TreeLinkNode*>());
        }
        ans[level-1].push_back(root);
        helper(root->left,  level+1, ans);
        helper(root->right, level+1, ans);
    }
};
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return ;
        TreeLinkNode dummy(-1);
        for(TreeLinkNode* curr = root, *prev = &dummy; curr; curr = curr->next){
            if(curr->left != NULL){
                prev->next = curr->left;
                prev = prev->next;
            }
            if(curr->right != NULL){
                prev->next = curr->right;
                prev = prev->next;
            }
        }
        connect(dummy.next);
    }
};
