class Solution {
public:
    // Apporach 1 (Do this!)
        // Time: O(n) Average & O(n^2) Worst - if collisions occurs
        // Space: O(n)
    // Approach 2
        // Time: O(n log n) - sort and match index+1
        // Space: O(1)
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> freqSet;
        for(auto x: nums){
            if(freqSet.count(x)) return true;
            freqSet.insert(x);
        }
        return false;
    }
};