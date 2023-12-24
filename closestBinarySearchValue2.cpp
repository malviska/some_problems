class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        stack<TreeNode*> st;
        int bottom = -INT_MAX;
        int top = INT_MAX;
        TreeNode* node = root;
        while(!st.empty() || node != nullptr){
            if(node != nullptr){
                st.push(node);
                node = node->left;
            }else{
                node = st.top();
                st.pop();
                if(node->val > target){
                    top = node->val;
                    break;
                }else{
                    bottom = node->val;
                }
                
                node = node->right;
            }
        }
        double diff1 = abs(target - bottom);
        double diff2 = abs(target - top);
        return (diff1 <= diff2) ? bottom : top;
    }
};
