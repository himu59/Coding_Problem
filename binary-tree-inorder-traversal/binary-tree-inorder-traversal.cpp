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
    vector<int> inorderTraversal(TreeNode* root) {
        if(not root) return {};
        vector<int> ans;
        
        while(root) {
            cout<<root->val<<' ';
            if(root->left) {
                TreeNode* L = root->left;
                
                while(L->right and L->right != root) {
                    L = L->right;
                }
                if(L->right == NULL) {
                    L->right = root;
                    root = root->left;
                }else {
                    L->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }else {
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};