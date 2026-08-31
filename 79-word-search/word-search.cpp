class Solution {
public:
    
    //optimal : O(mn × 4^L) time, O(L) space where L = recursion stack space
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }

    bool dfs(int i, int j, int k, vector<vector<char>> & board, string word){
        int m = board.size();
        int n = board[0].size();
        int l = word.length();

    
        if(i < 0 || i >= m || j < 0 || j >= n || k >= l) return false;

        if(board[i][j] != word[k]) return false;
        if(k == l - 1) return true;

        char temp = board[i][j];
        board[i][j] = '#';

        int left = dfs(i,j-1,k+1,board,word);
        int right = dfs(i,j+1,k+1,board,word);
        int down = dfs(i+1,j,k+1,board,word);
        int up = dfs(i-1,j,k+1,board,word);

        board[i][j] = temp;

        return left || right || up || down;
    }

    /*
    //Brute : O(mn × 4^L) time, O(mn + L) space
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(i, j, 0, board, word, visited))
                    return true;
            }
        }
        return false;
    }

    bool dfs(int i, int j, int k, vector<vector<char>> & board, string word,vector<vector<bool>> &visited){
        int m = board.size();
        int n = board[0].size();
        int l = word.length();

    
        if(i < 0 || i >= m || j < 0 || j >= n || k >= l) return false;
        if(visited[i][j]) return false;

        if(board[i][j] != word[k]) return false;
        if(k == l - 1) return true;

        visited[i][j] = 1;

        int left = dfs(i,j-1,k+1,board,word,visited);
        int right = dfs(i,j+1,k+1,board,word,visited);
        int down = dfs(i+1,j,k+1,board,word,visited);
        int up = dfs(i-1,j,k+1,board,word,visited);

        visited[i][j] = 0;

        return left || right || up || down;
    }
    */
};