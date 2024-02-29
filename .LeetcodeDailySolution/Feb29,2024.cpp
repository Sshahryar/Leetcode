class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);

        int level = 0;

        while(!q.empty()){

            int n = q.size();
            int t1,t2 = 0;

            if(level%2 == 0) t1 = -1;
            else t2 = INT_MAX;

            for(int i = 0; i < n; i++){
                TreeNode* te = q.front();
                q.pop();

                if(level %2 == 0){
                    if(te->val %2 == 0) return false;
                    if(te->val <= t1) return false;

                    t1 = max(t1,te->val);
                }
                else{
                    if(te->val%2 != 0) return false;
                    if(te->val >= t2) return false;

                    t2 = min(t2,te->val);
                }

                if(te->left) q.push(te->left);
                if(te->right) q.push(te->right);
            }
            level++;
        }
        return true;
    }
};
