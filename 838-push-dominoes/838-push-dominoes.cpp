class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        
        vector<int> right(n);
        vector<int> left(n);
        
        char prev = '.';
        int count = 1;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == 'L') {
                right[i] = 0;
                prev = 'L';
            }
            else if(s[i] == 'R') {
                right[i] = 0;
                count = 1;
                prev = 'R';
            }
            else {
                if(prev == 'R') {
                    right[i] = count;
                    count++;
                }
                else {
                    right[i] = 0;
                }
            }
        }
        
        prev = '.';
        count = 1;
        
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == 'R') {
                right[i] = 0;
                prev = 'R';
            }
            else if(s[i] == 'L') {
                right[i] = 0;
                prev = 'L';
                count = 1;
            }
            else {
                if(prev == 'L') {
                    left[i] = count;
                    count++;
                }
                else {
                    left[i] = 0;
                }
            }
        }
        
        string ans;
        
        for(int i = 0; i < n; i++) {
            if(left[i] == right[i]) {
                ans.push_back(s[i]);
            }
            else if(right[i] == 0 && left[i] != 0) {
                ans.push_back('L');
            }
            else if(right[i] != 0 && left[i] == 0) {
                ans.push_back('R');
            }
            else if(right[i] < left[i]) {
                ans.push_back('R');
            }
            else if(left[i] < right[i]) {
                ans.push_back('L');
            }
        }
        return ans;
    }
};