class Solution {
public:
    // Time: O(log n) | Space: O(1)
    int search(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(nums[mid] == target) return mid;
            // left side sorted
            if(nums[mid] >= nums[j]){
                if(nums[i] <= target && target <= nums[mid]) j=mid-1;
                else i=mid+1;
            }
            else{ // nums[mid] < nums[j] - right side sorted
                if(nums[mid] <= target && target <= nums[j]) i=mid+1;
                else j=mid-1;
            }
        }
        return -1;
    }
};