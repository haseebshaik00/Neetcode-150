class Solution {
public:
    // Time: O(n log M) | Space: O(1)
    // n = piles.size(), M = max(piles)
    // Search Space - O to M
    bool canFinish(vector<int>& piles, int h, int mid){
        long long int timeTaken = 0;
        // ceil(x / mid) = (x + mid - 1) / mid
        for(auto &x: piles) timeTaken += (x+mid-1)/mid;
        return timeTaken <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1, j=*max_element(piles.begin(), piles.end());
        int ans = j; // can initialize to j instead of 1e9
        while(i<=j){
            int mid = i + (j-i)/2;
            if(canFinish(piles, h, mid)){
                ans = mid; // No need of - ans = min(ans, mid);
                j = mid-1;
            }
            else i=mid+1;
        }
        return ans; // this can also be i as i ends up at the minimal valid speed
    }
};