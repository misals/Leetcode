class Solution {
public:
    int minPartitions(string s) {
        char ch = '0';
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] >= ch) {
                ch = s[i];
            }
        }
        return (ch - '0');
    }
};