class Solution {
public:
    // Time: O(n) | Space: O(1)
    int maxProfit(vector<int>& prices) {
        int ans=0, currMin=prices[0];
        for(auto &x: prices){
            if(currMin > x) currMin = x;
            ans = max(ans, x-currMin);
        }
        return ans;
    }
};
