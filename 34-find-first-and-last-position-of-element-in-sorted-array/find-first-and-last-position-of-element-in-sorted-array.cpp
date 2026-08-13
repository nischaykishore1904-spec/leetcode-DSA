class Solution {
    int firstOccurance(vector<int>& nums, int target){
        int st = 0, end = nums.size() - 1;
        int ans = -1;
        while(st <= end){
            int mid = st + (end - st)/2;
            
            if(nums[mid] == target){
               ans = mid;
               end = mid - 1; // SEARCH ONLY LEFT SIDE
            }
            else if(nums[mid] < target){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
    int lastOccurance(vector<int>& nums, int target){
        int st = 0, end = nums.size() - 1;
        int ans = -1;
        while(st <= end){
            int mid = st + (end - st)/2;
            
            if(nums[mid] == target){
               ans = mid;
               st = mid + 1; // SEARCH ONLY LEFT SIDE
            }
            else if(nums[mid] < target){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
public:

    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccurance(nums,target), lastOccurance(nums,target)};
    }
};