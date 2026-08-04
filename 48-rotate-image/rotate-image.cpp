class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n,vector<int>(n));

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size(); j++){

                ans[j][matrix.size()-1-i] = matrix[i][j];
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size(); j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};