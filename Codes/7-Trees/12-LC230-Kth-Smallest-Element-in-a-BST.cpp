class Solution {
public:
    // Time: O(n) | Space: O(1)
    int ans = -1, count=0;
    void dfs(TreeNode* root, int k){
        if(!root || ans!=-1) return;
        // if(!root || cnt >= k) return;
        dfs(root->left, k);
        if(++count == k){
            ans = root->val;
            return;
        }
        dfs(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};

// Follow-up: https://chatgpt.com/share/692daebe-7ac0-800d-892c-ddc204290689