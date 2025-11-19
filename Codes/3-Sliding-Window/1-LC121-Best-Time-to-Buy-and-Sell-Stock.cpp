class Solution {
public:
    // Time: O(n) | Space: O(1)
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), ans = 0, currMin=0;
        for(int i=1; i<n; ++i){
            if(prices[i] < prices[currMin]) currMin = i;
            else ans = max(ans, prices[i]-prices[currMin]);
        }
        return ans;
    }
};
