class Solution {
public:
    
    void generateAll(int col, vector<string> &board, int n, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int &ans) {
        if(col == n) {
            ans++;
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(leftRow[row] == 0 && upperDiagonal[row+col] == 0 && lowerDiagonal[n-1+col-row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[row+col] = 1;
                lowerDiagonal[n-1+col-row] = 1;
                generateAll(col + 1, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[row+col] = 0;
                lowerDiagonal[n-1+col-row] = 0;
            }
        }
    }
    
    
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++) {
            board[i] = s;
        }
        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2*n-1, 0);
        vector<int> lowerDiagonal(2*n-1, 0);
        
        generateAll(0, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);
        return ans;
    }
};