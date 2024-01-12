class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
            return 0;

        int minVal = root->val, maxVal = root->val;

        differ(root, minVal, maxVal);

        return diff;
    }
public:
    int diff = 0;
    void differ(TreeNode* root, int minVal, int maxVal) {
        if (!root)
            return;

        diff = max(diff, max(abs(minVal - root->val), abs(maxVal - root->val)));
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        differ(root->left, minVal, maxVal);
        differ(root->right, minVal, maxVal);
    }
};
