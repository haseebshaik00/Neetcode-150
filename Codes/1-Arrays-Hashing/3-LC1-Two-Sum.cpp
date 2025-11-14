class Solution {
public:
    // Time: O(n) | Space: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        index.reserve(nums.size());
        for(int i=0; i<nums.size(); ++i){
            int second = target-nums[i];
            if(index.count(second)) return {i, index[second]};
            index[nums[i]] = i;
        }
        return {-1, -1};
    }
};