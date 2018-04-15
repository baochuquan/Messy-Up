/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* ptr = head;
        while(ptr){
            ptr = ptr->next;
            n++;
        }
        ListNode* gPtr = head;
        return helper(0, n-1, gPtr);
    }
    TreeNode* helper(int l, int r, ListNode*& gPtr){
        if(l > r)
            return NULL;
        int m = (l+r)/2;
        TreeNode* left = helper(l, m-1, gPtr);
        TreeNode* root = new TreeNode(gPtr->val);
        gPtr = gPtr->next;
        root->left = left;
        root->right = helper(m+1, r, gPtr);
        return root;
    }
};
