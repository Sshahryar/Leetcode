class Solution {
private:

    string res = "~"; 

    void dfs(TreeNode* root, string str) {

        if(root == nullptr){
            return;
        }
        str = char('a' + root->val) + str;

        if(root->left == nullptr && root->right == nullptr){
            res = min(res, str);       
        }
        dfs(root->left, str);
        dfs(root->right, str);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        
        return res;
    }
};
