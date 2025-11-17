class Solution {
public:
    // Time: O(n) | Space: O(1)
    bool isPalindrome(string s) {
        int i=0, j=s.length()-1;
        while(i<j){
            char a = s[i], b=s[j];
            if(!isalnum(a)) ++i;
            else if(!isalnum(b)) --j;
            else{
                if(tolower(a) != tolower(b)) return false;
                ++i; --j;
            }
        }
        return true;
    }
};