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
    int helper(TreeNode* root,int &res) {
        if(root == NULL) return -10000000; //base case
        // if(root->left == NULL and root->right == NULL) return root->val; //base case
        
        int l = helper(root->left,res); // recusive intution
        int r = helper(root->right,res); // recusive intution
        
        int tmp = max(max(l,r)+root->val , root->val); // self work
        int ans = max(  {  l , r , l+r+root->val , l+root->val , r+root->val , root->val }   );
        res = max(res,ans);
        
        return tmp;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL)  return 0;
        if(root->left == NULL and root->right == NULL) return root->val;
        int res = INT_MIN;
        helper(root,res);
        return res;
    }
};