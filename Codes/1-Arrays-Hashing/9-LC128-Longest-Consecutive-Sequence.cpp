class Solution {
public:
    // Time: O(n) | Space: O(n)
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto &x: s){
            if(s.count(x - 1)) continue;
            int count = 0, curr = x;
            while(s.count(curr++)) count++;
            ans = max(ans, count);
        }
        return ans;
    }
};