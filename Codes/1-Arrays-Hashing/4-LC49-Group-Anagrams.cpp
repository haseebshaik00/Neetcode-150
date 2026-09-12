 // Time: O(n*m) | Space: O(n*m)
class Solution {
    public:
        string createKey(string x){
            string key = ""; int freq[26]={0};
            for(auto &y: x) ++freq[y-'a'];
            for(int i=0; i<26; ++i) 
                key += '#' + to_string(freq[i]);
            return key;
        }
    
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> ans;
            unordered_map<string, vector<string>> anaMap;
            for(auto &x: strs){
                string key = createKey(x);
                anaMap[key].push_back(x);
            }
            for(auto &[key, vectorVal]: anaMap) ans.push_back(vectorVal);
            return ans;
        }
    };