class Solution {
public:
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
};