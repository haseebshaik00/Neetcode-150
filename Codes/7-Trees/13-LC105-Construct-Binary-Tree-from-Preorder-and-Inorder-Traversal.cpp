// Approach 1
class Solution {
public:
    // Time: O(n^2) | Space: O(1)
    int idx = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int s, int e){
        if(s > e) return nullptr;
        int curr = preorder[idx++], i = s;
        TreeNode *newNode = new TreeNode(curr);
        for(; i<=e; ++i) if(curr == inorder[i]) break;
        newNode->left = build(preorder, inorder, s, i-1);
        newNode->right = build(preorder, inorder, i+1, e);
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, n-1);
    }
};

// Approach 2: Time: O(n) | Space: O(n)
    unordered_map<int, int> inMap; int idx = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int s, int e){
        if(s>e) return nullptr;
        int curr = preorder[idx++];
        TreeNode *newNode = new TreeNode(curr);
        int i = inMap[curr];
        newNode->left = build(preorder, inorder, s, i-1);
        newNode->right = build(preorder, inorder, i+1, e);
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0; i<n; ++i) inMap[inorder[i]] = i;
        return build(preorder, inorder, 0, n-1);
    }

    