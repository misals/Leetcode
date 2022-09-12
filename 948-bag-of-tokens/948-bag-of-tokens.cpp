class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        int n = tokens.size();
        
        int ans = 0;
        int low = 0;
        int high = n - 1;
        int sum = 0;
        int score = 0;
        
        while(low <= high) {
            if(power >= tokens[low]) {
                power -= tokens[low];
                ans++;
                low++;
            }
            else if(ans >= 1){
                power += tokens[high];
                high--;
                ans--;
            }
            else {
                high--;
            }
            score = max(score, ans);
        }
        return score;
    }
};