// Time: O(n) | Space: O(1)
    int ans = 0;
    int maxD(TreeNode* root){
        if(!root) return 0;
        int l = maxD(root->left);
        int r = maxD(root->right);
        ans = max(ans, l+r); // subTree = left + right
        return 1+max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxD(root);
        return ans;
    }