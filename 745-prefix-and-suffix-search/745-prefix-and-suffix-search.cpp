class WordFilter {
public:
    unordered_map<string, int> mp;
    WordFilter(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i < n; i++) {
            string prefix = "";
            for(int j = 0; j <= words[i].size(); j++) {
                string suffix = "";
                for(int k = words[i].size() - 1; k >= 0; k--) {
                    suffix = words[i][k] + suffix;
                    mp[prefix + "-" + suffix] = i;
                }
                prefix = prefix + words[i][j];
            }
        }
    }
    
    int f(string prefix, string suffix) {
        if(mp.find(prefix + "-" + suffix) != mp.end()) {
            return mp[prefix + "-" + suffix];
        } 
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */