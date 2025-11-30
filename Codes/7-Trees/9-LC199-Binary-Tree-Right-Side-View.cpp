class Solution {
public:
    // Time: O(n) | Space: O(h)
    vector<int> ans;
    void dfs(TreeNode* root, int level){
        if(!root) return;
        if(ans.size() == level) ans.push_back(root->val);
        dfs(root->right, level+1);
        dfs(root->left, level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};