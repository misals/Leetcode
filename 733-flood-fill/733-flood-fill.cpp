class Solution {
public:
    int di[4] = {0, -1, 0, 1};
    int dj[4] = {-1, 0, 1, 0};
    
    void floodFill(int x, int y, vector<vector<int>> &image, vector<vector<int>> &res, int color, int newColor, int n, int m) {
        for(int i = 0; i < 4; i++) {
            int a = x + di[i];
            int b = y + dj[i];
            if(a >= 0 && a < n && b >= 0 && b < m && image[a][b] == color && res[a][b] != newColor) {
                res[a][b] = newColor;
                floodFill(a, b, image, res, color, newColor, n, m);
            }
        }
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        int color = image[sr][sc];
        vector<vector<int>> res = image;
        floodFill(sr, sc, image, res, color, newColor, n, m);
        res[sr][sc] = newColor;
        return res;
    }
};