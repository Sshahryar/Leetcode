class Solution {
public:
    static void f(TreeNode* root, int level, long long* sum, int& sz) {

        if (sz <= level)
            sz++;

        sum[level] += root->val;

        if (root->left)
            f(root->left, level + 1, sum, sz);
        if (root->right)
            f(root->right, level + 1, sum, sz);
    }
    static long long kthLargestLevelSum(TreeNode* root, int k) {
        long long sum[100000] = {0};
        int sz = 0;
        f(root, 0, sum, sz);

        if (sz < k)
            return -1;

        nth_element(sum, sum + (k - 1), end(sum), greater<>());

        return sum[k - 1];
    }
};
