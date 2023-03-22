class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, int> mp;
        for(auto it : wordList) {
            mp[it] = 1;
        }
        if(mp.find(endWord) == mp.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int level = 0;
        
        while(!q.empty()) {
            int n = q.size();
            level++;
            for(int i = 0; i < n; i++) {
                string s = q.front();
                q.pop();
                
                if(s == endWord) return level;
                int len = s.size();
                
                for(int j = 0; j < len; j++) {
                    char c = s[j];
                    
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        s[j] = ch;
                        
                        if(mp.find(s) != mp.end()) {
                            q.push(s);
                            mp.erase(s);
                        }
                    }
                    s[j] = c;
                }
                
            }
        }
        return 0;
    }
};