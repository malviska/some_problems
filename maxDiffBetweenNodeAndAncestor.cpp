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
    int diff(TreeNode* root, int mx, int mn){
        if(root == nullptr){
            return abs(mx - mn);
        }
        mx = max(root->val, mx);
        mn = min(root->val, mn);
        int maxDiff = diff(root->left, mx, mn);
        maxDiff = max(maxDiff, diff(root->right, mx, mn));
        
        return maxDiff;
        
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        return diff(root, root->val, root->val);
        
    }
};
