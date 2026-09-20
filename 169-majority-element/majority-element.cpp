class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        for(auto val:freq){
            if(val.second > nums.size()/2){
                return val.first;
            }
        }
        return -1;
    }
};