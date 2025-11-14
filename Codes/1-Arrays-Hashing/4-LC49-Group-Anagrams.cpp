class Solution {
public:
    // Time: O(n*m) | Space: O(n*m)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> aMap;
        vector<vector<string>> ans;
        for(auto &x: strs){
            string key = ""; int freq[26] = {0};
            for (char ch : x) freq[ch - 'a']++;
            for(char i='a'; i<='z'; ++i) key += i + to_string(freq[i-'a'])+"#";
            aMap[key].push_back(x);
        }
        for(auto &x: aMap) ans.push_back(x.second);
        return ans;
    }
};