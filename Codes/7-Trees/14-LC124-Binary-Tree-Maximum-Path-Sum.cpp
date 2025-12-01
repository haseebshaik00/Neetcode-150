class Solution {
public:
    // Time: O(n) | Space: O(1)
    int ans = -1e9;
    int dfs(TreeNode* root){
        if(!root) return 0;

        // Clever approach!
        // long long int l = max(0LL, findSum(root->left));
        // long long int r = max(0LL, findSum(root->right));
        // ans = max(ans, (long long)root->val + l + r);
        // return (long long)root->val + max(l, r);

        int left = dfs(root->left), right = dfs(root->right);
        int branchMaxOrAlone = max(root->val, root->val+max(left, right));
        ans = max(ans, max(branchMaxOrAlone, root->val+left+right)); // subranch
        return branchMaxOrAlone;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
