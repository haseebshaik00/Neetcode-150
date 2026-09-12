class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> freq;
        vector<vector<int>> v(n+1);
        for(auto &x: nums) ++freq[x];
        for(auto &x: freq) v[x.second].push_back(x.first);
        for(int i=n; i>=0; --i){
            for(auto &x: v[i]){
                ans.push_back(x);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};

/* Concept 3: When to use direct vector declaration & vector.reserve()?
vector<vector<int>> bucket(n+1); creates n+1 actual elements, so bucket[i] is valid.
vector<int> a(5);           // size = 5 → a[3] is valid and equals 0

bucket.reserve(n+1); only reserves memory; size stays 0, so bucket[i] is invalid until elements are added.
vector<int> b; b.reserve(5); // size = 0 → b[3] is invalid
*/

/* Concept 4: When to use vector & set | vector.push_back() & unordered_set.insert()?
vector.push_back() → amortized O(1)
unordered_set.insert() → average O(1)
so it's better to use vector here!
*/

class Solution {
    public:
        // Approach 1:Time: O(n) | Space: O(n)
        // Approach 2: Time: O(n log k) | Space: O(n) - using priority queue
        vector<int> topKFrequent(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> ans;
            unordered_map<int, int> freq;
            vector<vector<int>> bucket(n+1);
            for(auto &x: nums) ++freq[x];
            for(auto &[num, size]: freq) bucket[size].push_back(num);
            for(int i=n; i>=0 && ans.size() < k; --i){
                for(auto &x: bucket[i]){
                    ans.push_back(x);
                    if(ans.size() == k) break;
                }
            }
            return ans;
        }
    };