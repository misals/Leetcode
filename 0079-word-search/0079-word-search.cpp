class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    int n, m;
    
    bool isValid(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }
    
    bool dfs(int i, int j, int ind, vector<vector<char>>& board, string &word) {
        if(ind == word.size()) {
            return true;
        }
        char ch = board[i][j];
        board[i][j] = '*';
        
        for(int x = 0; x < 4; x++) {
            int a = i + dx[x];
            int b = j + dy[x];
            
            if(isValid(a, b) && board[a][b] == word[ind]) {
                if(dfs(a, b, ind + 1, board, word)) {
                    return true;
                }
            }
        }
        
        board[i][j] = ch;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        
        if(word.size() > m * n) {
            return false;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, 1, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};