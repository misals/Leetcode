class Solution {
public:
    int solve(int start, int end, string &s, int k) {
        if(end - start < k) {
            return 0;
        }
        vector<int> freq(26, 0);
        for(int i = start; i < end; i++) {
            freq[s[i] - 'a']++;
        }
        
        for(int i = start; i < end; i++) {
            if(freq[s[i] - 'a'] < k) {
                int j = i + 1;
                
                while(j < end && freq[s[j] - 'a'] < k) {
                    j++;
                }
                
                return max(solve(start, i, s, k), solve(j, end, s, k));
            }
        }
        return end - start;
    }
    
    int longestSubstring(string s, int k) {
        int ans = solve(0, s.size(), s, k);
        return ans;
    }
};