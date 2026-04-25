// Approach 1: Time: O(26m) | Space: O(26)/O(1)
class Solution {
public:
    // Time: O(n)+O(n)+O(26)+O((m−n)⋅26)=O(m) | Space: O(1)
    bool checkInclusion(string s1, string s2) {
        int n=s1.length(), m=s2.length(), A[26]={0}, B[26]={0}, i=0;
        if(n>m) return false;
        for(auto &x: s1) ++A[x-'a'];
        for(; i<n; ++i) ++B[s2[i]-'a'];
        if(memcmp(A, B, sizeof(A)) == 0) return true;
        for(; i<m; ++i){
            --B[s2[i-n]-'a']; ++B[s2[i]-'a'];
            if(memcmp(A, B, sizeof(A)) == 0) return true;
        }
        return false;
    }
};

// Approach 1: Time: O(m) | Space: O(26)/O(1)
bool checkInclusion(string s1, string s2) {
        int n=s1.length(), m=s2.length(), A[26]={0}, B[26]={0}, i=0, matches=0;
        if(n>m) return false;
        for(auto &x: s1) ++A[x-'a'];
        for(; i<n; ++i) ++B[s2[i]-'a'];
        for(int k=0; k<26; ++k) if(A[k] == B[k]) ++matches;
        if(matches == 26) return true;
        for(; i<m; ++i){
            int in  = s2[i] - 'a';
            int out = s2[i - n] - 'a';
            // char going out of window
            if (B[out] == A[out]) --matches;
            --B[out];
            if (B[out] == A[out]) ++matches;
            // char coming into window
            if (B[in] == A[in]) --matches;
            ++B[in];
            if (B[in] == A[in]) ++matches;
            if (matches == 26) return true;
        }
        return false;
    }

// Similar to Approach 1!
bool checkInclusion(string s1, string s2) {
    int sl1=s1.length(), sl2=s2.length(), matches=0, A[26]={0}, B[26]={0};
    if(sl1 > sl2) return false;
    for(int i=0; i<sl1; ++i){
        ++A[s1[i]-'a'];
        ++B[s2[i]-'a'];
    }
    for(int i=0; i<26; ++i) if(A[i] == B[i]) ++matches;
    if(matches == 26) return true;
    for(int i=sl1; i<sl2; ++i){
        int in = s2[i]-'a', out = s2[i-sl1]-'a';
        if(A[in] == B[in]) --matches; ++B[in];
        if(A[in] == B[in]) ++matches;
        if(A[out] == B[out]) --matches; --B[out];
        if(A[out] == B[out]) ++matches;
        if(matches == 26) return true;
    }
    return false;
}
