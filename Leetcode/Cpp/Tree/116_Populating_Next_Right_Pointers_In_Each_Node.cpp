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

        TreeLinkNode* subHead = new TreeLinkNode(-1);
        TreeLinkNode* ptr;
        TreeLinkNode* cur;
        for(cur = root, ptr = subHead; cur != NULL; cur = cur->next){
            if(cur->left != NULL){
                ptr->next = cur->left;
                ptr = ptr->next;
            }
            if(cur->right != NULL){
                ptr->next = cur->right;
                ptr = ptr->next;
            }
        }
        connect(subHead->next);

    }
};
