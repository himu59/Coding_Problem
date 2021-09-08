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
    long sum = 0;
    void helper(TreeNode* root,int cur) {
        if(root == NULL) return;
        if(!root->left and !root->right) {
            cur = (cur * 10) + (root->val);
            cout<<cur<<' ';
            sum = sum + cur;
            cur = cur/10;
            return;
        }
        helper(root->left,cur*10+root->val);
        helper(root->right,cur*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        helper(root,0);
        return sum;
    }
};