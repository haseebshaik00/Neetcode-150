class Solution {
public:
    // Time: O(n) | Space: O(1)
    // If the interviewer asks about Unicode or arbitrary characters, you can say:
    // For general Unicode/an arbitrary charset, I’d switch to an 
    // unordered_map<char,int> or a map<char,int> instead of a fixed 26-array.

    // Context!
    // Unicode = the set of characters + code points (abstract)
    // UTF-8 (char), UTF-16 (char16_t), UTF-32 (char32_t) = encodings — 
    // how those code points are stored  as bytes in memory or files.
    // code point U+1F602 (😂) is one “character” in Unicode 
    // but in UTF-8(type of unicode encoding) it’s stored as 4 bytes.

    /*
    Quick mental model you can keep
    Unicode = giant map from characters → integers (code points).
    UTF-8 = store those integers in 1–4 bytes.
    UTF-16 = store them in 1–2 2-byte units.
    UTF-32 = store them in exactly 1 4-byte unit.
    In C++:
    std::string / char → usually UTF-8 bytes
    char16_t / std::u16string → UTF-16 units
    char32_t / std::u32string → UTF-32 units (1 per code point)
    */
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> freq(26, 0);
        for(int i=0; i<s.length(); ++i){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for(int i=0; i<26; ++i)
            if(freq[i]) return false;
        return true;
    }
};