class Solution {
public:
    // Time: O(n) | Space: O(1)
    // This is a variation of the Two Sum problem where the input array is sorted
    // Only difference here is that we don't need to use a hash map to store the indices
    // We save on O(n) space by using two pointers instead of a hash map because the input array is sorted.
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        while(i < j){
            int sum = numbers[i] + numbers[j] - target;
            if(!sum) break;
            else if(sum > 0) --j;
            else ++i;
        }
        return {i+1, j+1};
    }
};