class Solution {
    bool Divisor(vector<int>& nums, int threshold, int minDiv){
        long long div = 0;
        for(int i = 0; i < nums.size(); i++){
            div += ceil((double)nums[i]/minDiv);
        }
        return div <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1;
        int high = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            high = max(high, nums[i]);
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            if(Divisor(nums,threshold,mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};