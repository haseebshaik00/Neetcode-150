class Solution {
public:
    // Time: O(n^2) | Space: O(n^2)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int k=0; k<n-2; ++k){
            if(k>0 && nums[k] == nums[k-1]) continue;
            int i=k+1, j=n-1;
            while(i<j){
                int sum = nums[i]+nums[j]+nums[k];
                if(!sum){
                    ans.push_back({nums[k], nums[i], nums[j]});
                    ++i; --j;
                    while(i<j && nums[i]==nums[i-1]) ++i;
                    while(i<j && nums[j]==nums[j+1]) --j;
                }
                else if(sum < 0) i++;
                else --j;
            }
        }
        return ans;
    }
};