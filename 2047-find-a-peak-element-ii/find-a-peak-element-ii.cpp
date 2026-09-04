class Solution {
    int maxElement(vector<vector<int>>& mat,int col){
        int maxEl = mat[0][col];
        int index = 0;
        for(int i = 1; i < mat.size(); i++){
            if(mat[i][col] > maxEl){
                maxEl = mat[i][col];
                index = i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int row = maxElement(mat, mid);
            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < m ? mat[row][mid + 1] : -1;

            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }
            else if(mat[row][mid] < left){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};