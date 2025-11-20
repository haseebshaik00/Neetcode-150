class Solution {
public:
    // Time: O(n) | Space: O(n)
    bool isValid(string s) {
        stack<char> st;
        for(auto &x: s){
            if(!st.empty() && ((x==')' && st.top()=='(') || 
                                (x==']' && st.top()=='[') ||
                                    (x=='}' && st.top()=='{'))) st.pop();
            else st.push(x);
        }
        return st.empty();
    }
};