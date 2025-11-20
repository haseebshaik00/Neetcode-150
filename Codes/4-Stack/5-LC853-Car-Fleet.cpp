class Solution {
public:
    // Approach 1: Use stack to maintain max time taken!
    // Time: O(n) + O(n log n) | Space: O(n)
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<double> st; vector<pair<int, double>> v;
        for(int i=0; i<n; ++i){
            double time = (target-position[i])*1.0/speed[i];
            v.push_back({position[i], time});
        }
        sort(v.rbegin(), v.rend());
        for(auto &[pos, t]: v){
            if(!st.empty() && t<=st.top()) continue;
            st.push(t);
        }
        return st.size();
    }

    // Approach 2: Ignore stack as max time taken can be maintained with a single var
    // Time: O(n) + O(n log n) | Space: O(n)
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(); vector<pair<int, double>> v;
        for(int i=0; i<n; i++){
            double time = (1.0 * (target-position[i]))/speed[i];
            v.push_back({position[i], time});
        }
        sort(v.rbegin(), v.rend());
        int ans=0; double lastTime=0;
        for (auto& [pos, time] : v) {
            if (time > lastTime) {
                ans++;    
                lastTime = time;
            }
        }
        return ans;
    }
};