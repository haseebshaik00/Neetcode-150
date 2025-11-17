class Solution {
public:
    // Time: O(n) | Space: O(1): output array not counted!
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), temp=1;
        vector<int> prod(n, 1);
        for(int i=1; i<n; ++i){
            temp *= nums[i-1];
            prod[i] = temp;
        } 
        temp = 1;
        for(int i=n-2; i>=0; --i){
            temp *= nums[i+1];
            prod[i] *= temp;
        }
        return prod;
    }
};