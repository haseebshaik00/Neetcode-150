// Apporach 1 : Time: O(64m)
class Solution {
public:
    bool checkEqual(int A[], int B[]){
        for(int i=0; i<64; ++i)
            if(A[i] < B[i]) return false;
        return true;
    }
    // Time: O(m) | Space: O(1)
    string minWindow(string s, string t) {
        int m=s.length(), n=t.length(), A[64]={0}, B[64]={0}, i=0, ans=1e9, start=0;
        if(n>m) return "";
        for(auto &x: t) B[x-'A']++;
        for(int j=0; j<m; ++j){
            A[s[j]-'A']++;
            while(checkEqual(A, B)){
                if(ans > j-i+1){
                    start = i;
                    ans = j-i+1;
                }
                --A[s[i]-'A']; ++i;
            }
        }
        return ((ans == 1e9) ? "" : s.substr(start, ans));
    }
};

// Apporach 1 : Time: O(m)
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(), m=t.length(), A[128]={0}, B[128]={0};
        if(m>n) return "";
        for(auto &c: t) B[c]++;
        int start=0, minLen=INT_MAX, left=0, count=0;
        for(int right=0; right<n; right++){
            char c = s[right];
            A[c]++;
            // A[c]<=B[c] -- increase count only when the window has all the 
            // chars are available!
            if(B[c]>0 && A[c]<=B[c]) count++;
            while(count == m){
                char d = s[left];
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    start = left;
                }
                // A[d]<=B[d] -- remove redundant chars from left of the window but 
                // dont decrease the count as they are extra!
                if(B[d]>0 && A[d]<=B[d]) count--;
                A[d]--;
                left++;
            }
        }
        return (minLen==INT_MAX) ? "" : s.substr(start, minLen);
    }
};