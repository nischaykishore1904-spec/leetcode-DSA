class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int curr = 0, prev = 0;
        int n = nums1.size(), m = nums2.size();
        for(int count = 0; count <= (m+n)/2; count++){
            prev = curr;
            if(i < n && ((j >= m) || nums1[i] <= nums2[j])){
                curr = nums1[i];
                i++;
            }
            else{
                curr = nums2[j];
                j++;
            }
        }
        if((m + n) % 2 == 1) return curr;
        return (prev + curr)/2.0;
    }
};