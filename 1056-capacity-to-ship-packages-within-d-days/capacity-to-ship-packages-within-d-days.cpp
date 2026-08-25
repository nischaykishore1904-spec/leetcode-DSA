class Solution {
    bool totalDays(vector<int>& weights,int currCapacity,int days){
        int day = 1, load = 0;
        for(int i = 0; i < weights.size(); i++){
            if(load + weights[i] > currCapacity){
                day += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return day <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN, high = 0;
        for(int i = 0; i < weights.size(); i++){
            low = max(low, weights[i]);
            high += weights[i];
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            if(totalDays(weights, mid, days)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};