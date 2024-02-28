class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* curr;
        queue<TreeNode*> Q; Q.push(root);

        while (!Q.empty()) {
            curr = Q.front(); Q.pop();
            if (curr->right) Q.push(curr->right);
            if (curr->left) Q.push(curr->left);
        }
        return curr->val;
    }
};
