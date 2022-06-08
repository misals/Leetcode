class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board) {
        if(board[i][j] == 'O') {
            board[i][j] = '*';
        
        
            if(i + 1 < board.size()) {
                dfs(i+1, j, board);
            }
            if(i - 1 >= 0) {
                dfs(i-1, j, board);
            }
            if(j + 1 < board[i].size()) {
                dfs(i, j+1, board);
            }
            if(j - 1 >= 0) {
                dfs(i, j-1, board);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) {
            return;
        }
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++) {
            dfs(i, 0, board);
            dfs(i, m - 1, board);
        }
        
        for(int i = 0; i < m; i++) {
            dfs(0, i, board);
            dfs(n - 1, i, board);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == '*') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};