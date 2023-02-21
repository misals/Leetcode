class Solution {
public:
    int solve(int i, int j, vector<int> &nums, int turn) {
        if(i > j) {
            return 0;
        }
        
        if(turn == 0) {
            return max(nums[i] + solve(i+1, j, nums, 1),
                      nums[j] + solve(i, j - 1, nums, 1));
        }
        
        return min(solve(i+1, j, nums, 0),
                  solve(i, j-1, nums, 0));
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        int firstPlayer = 0;
        int secondPlayer = 0;
        
        for(int i = 0; i < n; i++) {
            secondPlayer += nums[i];
        }
        
        firstPlayer = solve(0, n - 1, nums, 0);
        
        secondPlayer -= firstPlayer;
        
        return firstPlayer >= secondPlayer;
        
    }
};