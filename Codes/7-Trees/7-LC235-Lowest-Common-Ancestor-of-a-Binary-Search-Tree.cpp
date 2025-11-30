class Solution {
public:
    // Time: O(h) | Space: O(h)
    // where log(n) < h < n
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(p->val<root->val && root->val>q->val) return lowestCommonAncestor(root->left, p, q);
        if(p->val>root->val && root->val<q->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};