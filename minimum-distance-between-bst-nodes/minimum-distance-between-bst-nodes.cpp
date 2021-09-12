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
   
    int ans = INT_MAX;
    int prev = -1;
    int minDiffInBST(TreeNode * root) {
        // Write your code here.
        if(root->left) minDiffInBST(root->left);
        if(prev != -1) ans = min(ans , root->val - prev);
        prev = root->val;
        if(root->right) minDiffInBST(root->right);
        return ans;
    }
};