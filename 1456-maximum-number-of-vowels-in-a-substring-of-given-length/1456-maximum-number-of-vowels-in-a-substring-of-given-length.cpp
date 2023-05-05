class Solution {
public:
    
    int maxVowels(string s, int k) {
        int n = s.size();
        int ans = 0;
        int cnt = 0;
        
        for(int i = 0; i < k; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        
        for(int i = k; i < n; i++) {
            char ch = s[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                cnt++;
            }
            ch = s[i-k];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                cnt--;
            }
            ans = max(ans, cnt);
        }
        
        
        return ans;
    }
};