class Solution {
public:
    int maxHistogram(vector<int> &nums, int n) {
        int ans = 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> st1;
        stack<int> st2;
        
        for(int i = 0; i < n; i++) {
            while(!st1.empty() && nums[st1.top()] >= nums[i]) {
                st1.pop();
            }
            if(st1.empty()) {
                left[i] = 0;
            }
            else {
                left[i] = st1.top() + 1;
            }
            st1.push(i);
        }
        for(int i = n - 1; i >= 0; i--) {
            while(!st2.empty() && nums[st2.top()] >= nums[i]) {
                st2.pop();
            }
            if(st2.empty()) {
                right[i] = n - 1;
            }
            else {
                right[i] = st2.top() - 1;
            }
            st2.push(i);
        }
        for(int i = 0; i < n; i++) {
            ans = max(ans, (right[i] - left[i] + 1) * nums[i]);
        }
        return ans;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0) {
                    if(matrix[i][j] == '1') {
                        dp[i][j] = 1;
                    }
                }
                else {
                    if(matrix[i][j] == '1') {
                        if(matrix[i-1][j] == '1') {
                            dp[i][j] += dp[i-1][j] + 1;
                        }
                        else {
                            dp[i][j] = 1;
                        }
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int val = maxHistogram(dp[i], m);
            ans = max(ans, val);
        }
        return ans;
        
    }
};