class MinStack {
public:
    // Time: O(1) for all operations | Space: O(n)
    vector<pair<int, int>> v;
    MinStack() {}
    
    void push(int val) {
        int currMin = (!v.empty() && (v.back().second) < val) ? v.back().second : val;
        v.push_back({val, currMin});
    }
    
    void pop() {v.pop_back();}
    int top() {return v.back().first;}
    int getMin() {return v.back().second;}
};