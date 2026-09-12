class Solution {
public:
    // Time: O(n) | Space: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        index.reserve(nums.size());
        for(int i=0; i<nums.size(); ++i){
            int second = target-nums[i];
            if(index.count(second)) return {i, index[second]};
            // Concept 2: When to use [] AND count()?
            // if(indexMap[second]) return {i, indexMap[second]};
            // Example: nums = [2,7,11,15]; target = 9;
            // second = 9 - 2 = 7;
            // indexMap[7] = 0; -- 7 doesn't exist, so it inserts {7, 0}
            index[nums[i]] = i;
        }
        return {-1, -1};
    }
};