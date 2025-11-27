// Approach 1 - DFS
// Time: O(n) | Space: O(1)
    bool isSame(TreeNode *p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q || (p->val != q->val)) return false;
        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if ((root->val == subRoot->val) && isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }


// Approach 2 - BFS
// Time: O(n) | Space: O(n)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q || (p->val != q->val)) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if (!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front(); q.pop();
            if(curr->val == subRoot->val && isSameTree(curr, subRoot)) return true;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return false;
    }
};
