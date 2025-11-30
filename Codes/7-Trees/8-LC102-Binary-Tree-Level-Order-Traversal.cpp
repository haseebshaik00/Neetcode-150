// Approach 1 : Using senital of nullptr
class Solution {
public:
    // Time: O(n) | Space: O(n)
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int> curr;
        queue<TreeNode*> q;
        q.push(root); q.push(nullptr);
        while(!q.empty()){
            TreeNode *node = q.front(); q.pop();
            if(!node){
                if(!q.empty()) q.push(nullptr);
                ans.push_back(curr);
                curr.clear();
                continue;
            }
            curr.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return ans;
    }
};


// Approach 2: Avoid the senital crap - be clever!
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Time: O(n) | Space: O(n)
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans; 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> curr;
            curr.reserve(sz);
            for(int i=0; i<sz; ++i){
                TreeNode* temp = q.front(); q.pop();
                curr.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};