class Solution {
public:
    int di[4] = {0, -1, 0, 1};
    int dj[4] = {-1, 0, 1, 0};
    int n, m;
    
    bool isValid(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }
    
    bool dfs(int x, int y, vector<vector<char>>& board, string &word, int ind) {
        if(ind == word.size()) {
            return true;
        }
        char ch = board[x][y];
        board[x][y] = '*';
        for(int i = 0; i < 4; i++) {
            int a = x + di[i];
            int b = y + dj[i];
            if(isValid(a, b) && board[a][b] == word[ind]) {
                if(dfs(a, b, board, word, ind + 1) == true) {
                    return true;
                }
            } 
        }
        board[x][y] = ch;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 && word.size() == 0) {
            return true;
        }
        n = board.size();
        m = board[0].size();
        if(n == 1 && word.size() > m || (word.size() > n*m)) {
            return false;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, board, word, 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};