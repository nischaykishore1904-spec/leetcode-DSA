class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        long long int maxFreq = 0, r = 0, l = 0, total = 0;

        for(int r = 0; r < nums.size(); r++){
            total += nums[r];

            while(l + 1 <= r && (nums[r] * (r - l + 1) > total + k)){
                total -= nums[l];
                l++;
            }
            maxFreq = max(maxFreq, r - l + 1);
        }
        return maxFreq;
    }
};