class Solution {
public:
    // Time: O(n) | Space: O(1)
    int count=0;
    void dfs(TreeNode* root, int maxTillNow){
        if(!root) return;
        if(root->val >= maxTillNow) ++count;
        maxTillNow = max(maxTillNow, root->val);
        dfs(root->left, maxTillNow);
        dfs(root->right, maxTillNow);
    }

    int goodNodes(TreeNode* root) {
        dfs(root, -1e9);
        return count;
    }
};