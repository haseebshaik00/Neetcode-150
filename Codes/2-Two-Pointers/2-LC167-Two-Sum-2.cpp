class Solution {
public:
    // Time: O(n) | Space: O(1)
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