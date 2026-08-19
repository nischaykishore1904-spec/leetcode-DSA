class Solution {
public:
    long long maxElement(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    long long minTimeTaken(vector<int>& piles, int hourly) {
        long long totalhrs = 0;

        for(int i = 0; i < piles.size(); i++) {
            totalhrs += ceil((double)piles[i] / hourly);
        }

        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        long long st = 1, end = maxElement(piles);
        while(st <= end){
            long long mid = st + (end - st)/2;
            long long reqTime = minTimeTaken(piles,mid);
            if(reqTime <= h){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return st;
    }
};