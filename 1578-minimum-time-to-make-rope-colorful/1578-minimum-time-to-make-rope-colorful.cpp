class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        int n = s.size();
        int cnt = 0;
        char prev = s[0];
        int prevVal = neededTime[0];
        
        for(int i = 1; i < n; i++) {
            if(s[i] == prev) {
                cnt += min(neededTime[i], prevVal);
                prevVal = max(neededTime[i], prevVal);
                prev = s[i];
            }
            else {
                prev = s[i];
                prevVal = neededTime[i];
            }
        }
        return cnt;
    }
};