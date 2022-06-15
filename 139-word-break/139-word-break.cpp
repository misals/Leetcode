class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[s.size()+1];
        int n=s.size();

        memset(dp , false , sizeof(dp));
        dp[0]=true;


        for(int i=0; i<n;++i){
                if(!dp[i])continue;

                for(string x:wordDict){
                        int j;
                       j =i+x.size();
                        if(j<=n && s.substr(i , x.size())==x)dp[j]=true;
                }
        }
        return dp[n];
    }
};