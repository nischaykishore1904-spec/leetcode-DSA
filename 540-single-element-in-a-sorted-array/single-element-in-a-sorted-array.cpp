class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size() == 1 || nums[0] != nums[1]) return nums[0];
        
        if(nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];

        int st = 1, end = nums.size() - 2;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }
            if((mid % 2 == 1 && nums[mid] == nums[mid-1]) || (mid % 2 == 0 && nums[mid] == nums[mid+1])){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
            
        }
        return -1;
    }
};