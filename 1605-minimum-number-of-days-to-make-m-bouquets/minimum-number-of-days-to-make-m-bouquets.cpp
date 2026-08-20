class Solution {
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0, bouquet = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                bouquet += (cnt/k);
                cnt = 0;
            }
        }
        bouquet += (cnt/k);
        return bouquet >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = (long long)m * (long long)k;
        if(val > bloomDay.size()) return -1;
        int high = INT_MIN;
        int low = INT_MAX;
        for(int i = 0; i < bloomDay.size(); i++){
            high = max(high, bloomDay[i]);
            low = min(low, bloomDay[i]);
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(bloomDay, mid, m, k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};