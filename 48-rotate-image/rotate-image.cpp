class Solution {
public:
    //optimal : O(n2),O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //tranpose
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        int middle = n/2;
        if(n % 2 == 0) middle--;
        
        //reverse every row
        for(int j = 0; j <= middle; j++){
            for(int i = 0; i < n; i++){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
        
    }

    /*
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
    */
};