class Solution {
public:
    // Time: O(n*m) | Space: O(n*m)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> keyMap;
        for(auto &x: strs){
            string key = ""; int freq[26] = {0};
            for(auto &y: x) ++freq[y-'a'];
            for(char y='a'; y<='z'; ++y) key += y + to_string(freq[y-'a']) + "#";
            keyMap[key].push_back(x);
        }
        for(auto &[p, q]: keyMap) ans.push_back(q);
        return ans;
    }
};