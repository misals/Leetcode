class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = t.size();
        int m = s.size();
        
        int cnt = 0;
        int ind = 0;
        
        for(int i = 0; i < n; i++) {
            bool flag = false;
            for(int j = ind; j < m; j++) {
                if(t[i] == s[j]) {
                    cnt++;
                    ind = j + 1;
                    flag = true;
                    break;
                }
            }
            if(flag == false)
                break;
        }
        return n - cnt;
    }
};