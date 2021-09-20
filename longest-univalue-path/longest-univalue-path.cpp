/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int helper(TreeNode* root) {
        if(root == NULL) return 0;
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        l = (root->left and root->left->val == root->val) ? l+1 : 0;
        r = (root->right and root->right->val == root->val) ? r+1 : 0;
        
        ans = max(ans,l+r);
        return max(l,r);
    }
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return ans;
        
    }
};