class Solution {
public:
    //Brute : O(mn), O(mn)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int j = 0; j < m; j++){
            for(int i = n-1; i >=0 ; i--){
                ans[j][(n-1)-(i)] = matrix[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};