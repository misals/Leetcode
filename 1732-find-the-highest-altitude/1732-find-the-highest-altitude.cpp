class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans = 0;
        int prev = 0;
        
        for(int i = 0; i < n; i++) {
            int val = prev + gain[i];
            prev = val;
            ans = max(ans, val);
        }
        return ans;
        
    }
};