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
    int * bottom = nullptr;
    int * top = nullptr;
    int exact = false;
    bool go = true;
    
    void dfs(TreeNode* node, double target){
        if(node == nullptr){
            return;
        }
        dfs(node->left, target);
        if(!go){
            return;
        }
        if(node->val == target){
            go = false;
            exact = true;
            return;
        }
        if(node->val > target){
            go = false;
            top = &(node->val);
            return;
        }
        if(node->val < target)
            bottom = &(node->val);
        dfs(node->right, target);
    }
    int closestValue(TreeNode* root, double target) {
        double diff1, diff2;
        dfs(root, target);
        if(exact){
            return target;
        }
        if(bottom){
            diff1 = abs(target - *bottom);
        }else{
            return *top;
        }
        
        if(top){
            diff2 = abs(target - *top);
        }else{
            return *bottom;
        }
        
        if(diff1<=diff2){
            return *bottom;
        }else{
            return *top;
        }
    }
};
