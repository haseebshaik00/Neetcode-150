class Solution {
public:
    // Time: O(log(min(m, n))) | Space: O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        // We are BSing on the cut range of smaller array (nums1)
        // which can be 0 to m: total (m+1) cuts - hence hi is m & not m-1
        int lo=0, hi=m, half = (m+n+1)/2; 
        while(lo<=hi){
            int i = lo + (hi-lo)/2; //left array cut 
            // nums1[i] is right half & nums[i-1] is left half of nums1 array
            int j = half - i; //right array cut
            int L1 = (i==0) ? INT_MIN : nums1[i-1];
            int R1 = (i==m) ? INT_MAX : nums1[i];
            int L2 = (j==0) ? INT_MIN : nums2[j-1];
            int R2 = (j==n) ? INT_MAX : nums2[j];
            if(L1 <= R2 && L2 <= R1){
                if((m+n)%2) return max(L1, L2);
                else return (max(L1, L2) + min(R1, R2))*1.0/2;
            }
            else if(L1 > R2) hi = i-1;
            else lo = i+1;
        }
        return 0.0;
    }
};