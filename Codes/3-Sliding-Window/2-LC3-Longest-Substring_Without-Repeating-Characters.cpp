class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int ans=0, i=0;
            unordered_set<char> st;
            for(int j=0; j<s.length(); ++j){
                while(st.count(s[j])) st.erase(s[i++]);
                ans = max(ans, j-i+1);
                st.insert(s[j]);
            }
            return ans;
        }
    };