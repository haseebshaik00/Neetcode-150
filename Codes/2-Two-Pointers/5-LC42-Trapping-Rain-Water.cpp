class Solution {
public:
    // Time: O(n) | Space: O(1)
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1, ans = 0;
        int lmax=height[l], rmax=height[r];
        while(l <= r){
            if(lmax < rmax){
                ans += max(0, lmax-height[l]);
                lmax = max(lmax, height[l]);
                ++l;
            } else {
                ans += max(0, rmax-height[r]);
                rmax = max(rmax, height[r]);
                --r;
            }
        }
        return ans;
    }
};