class Solution {
public:
    // Time: O(n) | Space: O(1)
    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto &x: strs)
            encoded += to_string(x.length()) + "#" + x;
        return encoded;
    }
    // Time: O(n) | Space: O(n)
    vector<string> decode(string s) {
        int n = s.length(); string len="";
        vector<string> ans;
        for(int i=0; i<n; ++i){
            if(s[i] != '#') len += s[i];
            else{
                ans.push_back(s.substr(i+1, stoi(len)));
                i += stoi(len);
                len.clear();
            }
        }
        return ans;
    }
};
