class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        return countPseudoPalindromicPaths(root, 0);
    }
private:
    int countPseudoPalindromicPaths(TreeNode* node, int path) {
        if (!node) {
            return 0;
        }
        path ^= (1 << node->val);

        if (!node->left && !node->right) {
            return (path & (path - 1)) == 0 ? 1 : 0;
        }
        return countPseudoPalindromicPaths(node->left, path) + countPseudoPalindromicPaths(node->right, path);
    }
};
