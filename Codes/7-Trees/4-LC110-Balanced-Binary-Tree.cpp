// Time: O(n) | Space: O(1)
    bool ans = true;
    int checkBalanced(TreeNode* root){
        if(!root || !ans) return 0;
        int l = checkBalanced(root->left);
        int r = checkBalanced(root->right);
        if(abs(l-r) > 1) ans = false;
        return 1+max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        checkBalanced(root);
        return ans;
    }