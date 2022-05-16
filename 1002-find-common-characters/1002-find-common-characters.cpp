class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        int count[n][26];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 26; j++) {
                count[i][j] = 0;
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < words[i].size(); j++) {
                count[i][words[i][j] - 97]++;
            }
        }
        
        vector<string> res;
        string str;
        
        for(int i = 0; i < 26; i++) {
            int smallest = count[0][i];
            
            for(int j = 1; j < n; j++) {
                smallest = min(smallest, count[j][i]);
            }
            
            while(smallest--) {
                str = i + 'a';
                res.push_back(str);
            }
        }
        return res;
    }
};