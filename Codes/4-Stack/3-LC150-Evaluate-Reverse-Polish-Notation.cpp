class Solution {
public:
    int cal(int a, int b, string x){
        if(x == "+") return a+b;
        if(x == "-") return a-b;
        if(x == "*") return a*b;
        return a/b;
    }
    // Time: O(n) | Space: O(n)
    int evalRPN(vector<string>& tokens) {
        stack<int> st; string opt = "+-/*";
        for(auto &x: tokens){
            if(!st.empty() && opt.find(x) != string::npos){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(cal(a, b, x));
            }
            else st.push(stoi(x));
        }
        return st.top();
    }
};