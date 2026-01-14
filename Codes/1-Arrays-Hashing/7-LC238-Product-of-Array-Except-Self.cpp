class Solution {
public:
    // Time: O(n) | Space: O(1): output array not counted!
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), temp = nums[n-1];
        vector<int> ans(n, 1);
        for(int i=1; i<n; ++i)
            ans[i] = ans[i-1] * nums[i-1];
        for(int i=n-2; i>=0; --i){
            ans[i] *= temp;
            temp *= nums[i];
        }
        return ans;
    }
};