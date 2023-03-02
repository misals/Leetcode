class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int n = chars.size();
        
        for(int i = 0; i < n; i++) {
            int j;
            int cnt = 1;
            
            for(j = i + 1; j < n; j++) {
                if(chars[i] == chars[j]) {
                    cnt++;
                }
                else {
                    break;
                }
            }
            if(cnt == 1) {
                s += chars[i];
            }
            else {
                s += chars[i];
                string temp = to_string(cnt);
                s += temp;
                i = j - 1;
            }
        }
        int i;
        int sz = s.size();
        for(i = 0; i < sz; i++) {
            chars[i] = s[i];
        }
        return i;
    }
};