class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if(k % (m*n) == 0) return grid;
        if(k > m*n) k = k % (m*n);

        vector<vector<int>> ans(m, vector<int>(n));

        int total = m * n;
        k %= total;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int idx = i * n + j;
                int newIdx = (idx + k) % total;

                ans[newIdx / n][newIdx % n] = grid[i][j];
            }
        }

        return ans;
    }
};