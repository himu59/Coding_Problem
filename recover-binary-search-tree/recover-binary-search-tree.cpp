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
    
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* pre = NULL;
        
        while(root) {
            if(root->left) {
                TreeNode* tmp = root->left;
                while(tmp->right and tmp->right != root) {
                    tmp = tmp->right;
                }
                if(tmp->right == NULL) {
                    tmp->right = root;
                    root = root->left;
                }else {
                    if(pre and pre->val > root->val) {
                        if(!first) {first = pre; second = root;}
                        else {second = root;}
                    }
                    pre = root;
                    tmp->right = NULL;
                    root = root->right;
                }
            }else {
                if(pre and pre->val > root->val) {
                    if(!first) {first = pre; second = root;}
                    else {second = root;}
                }
                pre = root;
                root = root->right;
            }
        }
        if(first and second) {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }
};