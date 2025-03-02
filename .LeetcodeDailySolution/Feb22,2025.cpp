class Solution {
public:
    int i = 0;

    TreeNode* recoverFromPreorder(string& T, int depth = 0) {

        if (i >= T.size())
            return NULL;

        int D = 0;

        while (T[i] == '-')
            D++, i++;

        if (D < depth) {
            i -= D;

            return NULL;
        }
        int x = 0;

        while (isdigit(T[i])) {
            x = x * 10 + T[i] - '0';
            i++;
        }
        TreeNode* node = new TreeNode(x);

        node->left = recoverFromPreorder(T, depth + 1);
        node->right = recoverFromPreorder(T, depth + 1);

        return node;
    }
};
