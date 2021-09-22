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
    int ans;
    
    void helper(TreeNode* root,TreeNode* par,TreeNode* grand) {
        if(!root) return;
        helper(root->left,root,par);
        helper(root->right,root,par);
        
        if(grand and grand->val%2 == 0) ans+=root->val;
        if(grand) {
            cout<<grand->val<<' '<<root->val<<endl;
        }
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        ans = 0;
        helper(root,NULL,NULL);
        return ans;
    }
};