#define ll long long int 
// using ll = long long; - prefer this
class Solution {
public:
    // Time: O(n) | Space: O(1)
    bool checkValid(TreeNode* root, ll mini, ll maxi){
        if(!root) return true;
        if(mini >= root->val || root->val >= maxi) return false;
        return checkValid(root->left, mini, root->val) && 
               checkValid(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return checkValid(root, LONG_MIN, LONG_MAX);
    }
};