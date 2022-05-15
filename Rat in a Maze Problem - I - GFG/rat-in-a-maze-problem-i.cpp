// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void ratProblem(int i, int j, int n, vector<string> &ans, vector<vector<int>> &m, vector<vector<int>> &vis, string move, int di[], int dj[]) {
        if(i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for(int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if(nexti >= 0 && nexti < n && nextj >= 0 && nextj < n && !vis[nexti][nextj] && m[nexti][nextj] == 1) {
                vis[i][j] = 1;
                ratProblem(nexti, nextj, n, ans, m, vis, move + dir[ind], di, dj);
                vis[i][j] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        int di[] = {+1,0,0,-1};
        int dj[] = {0,-1,1,0};
        vector<vector<int>> vis(n, vector<int> (n, 0));
        if(m[0][0] == 1) {
            ratProblem(0,0, n, ans, m, vis, "" , di, dj);
        }
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends