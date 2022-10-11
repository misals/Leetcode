class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size();
        vector<int> v;
        
        for(int i = 0; i < n; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while(i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                v.push_back(num);
            }
        }
        int sz = v.size();
        for(int i = 1; i < sz; i++) {
            if(v[i] <= v[i-1]) {
                return false;
            }
        }
        return true;
    }
};