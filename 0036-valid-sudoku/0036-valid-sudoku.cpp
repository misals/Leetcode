class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool flag = true;
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    char ch = board[i][j];
                
                    for(int k = 0; k < 9; k++) {
                        if(k != j && board[i][k] == ch) {
                            flag = false;
                            break;
                        }
                    }

                    for(int k = 0; k < 9; k++) {
                        if(k != i && board[k][j] == ch) {
                            flag = false;
                            break;
                        }
                    }

                    int a = ((i / 3) * 3);
                    int b = ((j / 3) * 3);

                    int cnt = 0;
                    for(int m = a; m < a + 3; m++) {
                        for(int n = b; n < b + 3; n++) {
                            if(board[m][n] == ch) {
                                cnt++;
                            }
                        }
                    }

                    if(cnt >= 2) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag == false)
                break;
        }
        return flag;
    }
};