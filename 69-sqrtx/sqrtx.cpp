class Solution {
public:
    int mySqrt(int x) {
        int st = 1, end = x/2;
        if(x < 2) return x;

        while(st <= end){
            int mid = st + (end - st)/2;
            int curr = mid;
            if(mid == x/mid){
                return curr;
            } 
            else if(mid  < x/mid){
                st = mid + 1;

            }
            else{
                end = mid - 1;
            }
        }
        return end;
    }
};