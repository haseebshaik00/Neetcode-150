class Solution {
public:
    // Time: O(n) | Space: O(n)
    // Approach 2: Time: O(n log k) | Space: O(n) - using priority queue
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> freq;
        vector<unordered_set<int>> v(n+1);
        for(auto &x: nums) ++freq[x];
        for(auto &x: freq) v[x.second].insert(x.first);
        for(int i=n; i>=0; --i){
            for(auto &x: v[i]){
                ans.push_back(x);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};