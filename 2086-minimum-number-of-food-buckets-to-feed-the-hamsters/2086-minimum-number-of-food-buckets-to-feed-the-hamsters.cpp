class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.size();
        bool flag = true;
        
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == 'H') {
                if(i == 0) {
                    if(i + 1 < n && s[i+1] == '.') {
                        s[i+1] = 'F';
                        cnt++;
                    }
                    else {
                        return -1;
                    }
                }
                else {
                    if(i - 1 >= 0 && s[i-1] == 'F') {
                        
                    }
                    else if(i + 1 < n && s[i+1] == '.') {
                        s[i+1] = 'F';
                        cnt++;
                    }
                    else if(i - 1 >= 0 && s[i-1] == '.') {
                        s[i-1] = 'F';
                        cnt++;
                    }
                    else {
                        return -1;
                    }
                }
            }
        }
        return cnt;
    }
};