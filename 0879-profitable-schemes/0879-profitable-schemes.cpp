constexpr static int MOD = 1e9 + 7;
class Solution {
public:    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int size = group.size();
        vector<vector<int>> prev(n+1, vector<int>(minProfit + 1));
        int N = n, MinProfit = minProfit;
        for(int i=size;i>=0;i--){
            auto cur = prev;
            for(int n=0;n<=N;n++){
                for(int minProfit=0; minProfit<=MinProfit; minProfit++){                    
                    //No Crime/Criminal Left Check MinProfit Left
                    if(i==group.size() or n<=0) cur[n][minProfit] = !minProfit;
                    else{
                        int pick = 0, skip = 0;
                        if(group[i] <= n) 
                            pick = prev[n-group[i]][max(0, minProfit-profit[i])];
                        skip = prev[n][minProfit];

                        cur[n][minProfit] = (pick + skip) % MOD;     
                    }
                }
            }
            prev = cur;
        }
        
        return prev[N][MinProfit];
    }
};