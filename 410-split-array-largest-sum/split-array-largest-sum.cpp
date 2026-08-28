class Solution {
    bool canSplit(vector<int>& nums, int maxSum, int k) {
        int subarrays = 1;
        int sum = 0;

        for (int num : nums) {
            if (sum + num > maxSum) {
                subarrays++;
                sum = num;
            }
            else {
                sum += num;
            }
        }

        return subarrays <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;

        for (int num : nums) {
            low = max(low, num);
            high += num;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, mid, k)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};