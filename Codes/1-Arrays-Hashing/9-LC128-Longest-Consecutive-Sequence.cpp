class Solution {
public:
    // Time: O(n) | Space: O(n)
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for(auto &x: st){
            if(st.count(x-1)) continue;
            int curr = x, count=0;
            while(st.count(curr++)) ans = max(ans, ++count);
        }
        return ans;
    }
};