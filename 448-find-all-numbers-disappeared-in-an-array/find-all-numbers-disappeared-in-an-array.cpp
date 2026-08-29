class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Mark the presence of every number
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);

            nums[num - 1] = -abs(nums[num - 1]);
        }

        vector<int> ans;

        // Positive value means that number is missing
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};