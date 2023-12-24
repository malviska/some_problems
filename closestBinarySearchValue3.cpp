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
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        
        while (root) {
            double comp1 = abs(target - root->val);
            double comp2 = abs(target - closest);
            if(comp1 == comp2) {
                closest = (closest < root->val) ? closest : root->val;
            }
            if (comp1 < comp2) {
                closest = root->val;
            }
            if (target < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        
        return closest;
    }
};



