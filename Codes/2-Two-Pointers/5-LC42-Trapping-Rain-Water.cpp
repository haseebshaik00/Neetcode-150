class Solution {
public:
    // Time: O(n) | Space: O(1)
    int trap(vector<int>& height) {
        int n=height.size(), ans=0;
        int i=0, j=n-1, lmax=height[i], rmax=height[n-1];
        while(i<=j){
            if(lmax<=rmax){
                ans += max(0, lmax-height[i]);
                lmax = max(lmax, height[i]);
                ++i;
            }
            else{
                ans += max(0, rmax-height[j]);
                rmax = max(rmax, height[j]);
                --j;
            }
        }
        return ans;
    }
};