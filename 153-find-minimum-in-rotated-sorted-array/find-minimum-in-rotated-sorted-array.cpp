class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int st = 0, end = nums.size() - 1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[st] <= nums[mid]){
                ans = min(ans, nums[st]);
                st = mid + 1;
            }
            else{
                ans = min(nums[mid], ans);
                end = mid - 1;
            }
        }
        return ans;
    }
};