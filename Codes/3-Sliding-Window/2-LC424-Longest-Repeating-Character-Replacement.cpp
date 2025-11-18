class Solution {
public:
    // Approach 1: Time: O(26*n) | Space: O(1)
    int characterReplacement(string s, int k) {
        int freq[26]={0}, i=0, j=0, n=s.length(), ans=0;
        for(; j<n; ++j){
            ++freq[s[j]-'A'];
            while((j-i+1)-(*max_element(freq, freq+26)) > k) --freq[s[i++]-'A'];
            ans = max(ans, j-i+1);
        }
        return ans;
    }
    
    // Approach 2: Time: O(n) | Space: O(1)
    int characterReplacement(string s, int k) {
        int freq[26]={0}, i=0, j=0, n=s.length(), ans=0, maxF=0;
        for(; j<n; ++j){
            ++freq[s[j]-'A'];
            maxF = max(maxF, freq[s[j]-'A']);
            while((j-i+1)-maxF > k) --freq[s[i++]-'A'];
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};