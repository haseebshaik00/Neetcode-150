class Solution {
public:
    // Time: O(n) | Space: O(1)
    // Intuition: in each iteration, take max of prev area and current area, then increase the smaller height to get the max ans!
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1, ans=0;
        while(i<j){
            ans = max(ans, (j-i)*min(height[i], height[j]));
            height[i] < height[j] ? ++i : --j;
        }
        return ans;
    }
};