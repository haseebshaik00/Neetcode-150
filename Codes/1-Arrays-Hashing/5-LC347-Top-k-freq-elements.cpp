class Solution {
public:
    // Time: O(n) | Space: O(n)
    // Approach 2: Time: O(n log k) | Space: O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto &x: nums) freq[x]++;
        vector<vector<int>> v(nums.size()+1);
        for(auto &x: freq) v[x.second].push_back(x.first);
        vector<int> ans;
        for(int i=nums.size(); i>=0; --i){
            for(auto &x: v[i]){
                ans.push_back(x);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};