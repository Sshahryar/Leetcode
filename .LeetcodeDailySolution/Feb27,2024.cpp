class Solution {
public:

    int helper(TreeNode*root, int&ans) {
        if (!root) return 0;
        int l = helper(root->left, ans);
        int r = helper(root->right, ans);

        ans = max(ans, l+r);

        return 1 + max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        helper(root, ans);
        return ans;  
    }
};
