class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<int> after(2*k+1, 0);
        vector<int> curr(2*k+1, 0);
        
        for(int ind = n - 1; ind >= 0; ind--) {
            for(int tran = 0; tran < 2*k; tran++) {
                if(tran % 2 == 0) {
                    curr[tran] = max(-prices[ind] + after[tran+1],
                              0 + after[tran]);
                }
                else {
                    curr[tran] = max(prices[ind] + after[tran+1],
                            0 + after[tran]);
                }
            }
            after = curr;
        }
        
        return after[0];
        
    }
};