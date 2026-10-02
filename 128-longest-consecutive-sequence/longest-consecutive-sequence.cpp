class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int currSmallest = INT_MIN;
        int longest = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]-1 == currSmallest){
                count += 1;
                currSmallest = nums[i];
            }
            else if(nums[i] != currSmallest){
                count = 1;
                currSmallest = nums[i]; 
            }
            
            
            longest = max(longest, count);
        }
        return longest;
    }
};