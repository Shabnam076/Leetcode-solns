class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int col0 = 1;
        for(int i = 0; i < n; i++){
            if(matrix[i][0] == 0) col0 = 0;
        }
        for(int j = 0; j < m; j++){
            if(matrix[0][j] == 0)matrix[0][0] = 0;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){  //row = matrix[][0], col = matrix[0][]
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        //setting 0's
        // setting rows from 1 to n to 0 if reqd
        for(int i = 1; i < n; i++){
            if(matrix[i][0] != 0)continue;
            for(int j = 1; j < m; j++){
                matrix[i][j] = 0;
            }
        }

        //setting col from 1 to m to 0 if needed
        for(int j = 1; j < m; j++){
            if(matrix[0][j] != 0) continue;
            for(int i = 1; i < n; i++){
                matrix[i][j] = 0;
            }
        }
        
        //matrix[0][0] is 0 if any first row ele contained 0 ie 0th row will be 0
        if(matrix[0][0] == 0){
            for(int j = 1; j < m; j++){
                matrix[0][j] = 0;
            }
        }

        //col0 is 0 if any element in first col had 0 ie..entire 0th col will be set to 0
        if(col0 == 0){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
    /*
    
    //Better : O(nm), O(n+m)
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set<int> r,c;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }

        // set rows to 0
        for(int i = 0; i < n; i++){
            if(!r.count(i))continue;
            for(int j = 0; j < m; j++){
                matrix[i][j] = 0;
            }
        }

        //set columns to 0
        for(int j = 0; j < m; j++){
            if(!c.count(j))continue;
            for(int i = 0; i < n; i++){
                matrix[i][j] = 0;
            }
        }
    }
    */
};