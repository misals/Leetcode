class Solution {
public:
    unordered_map<string, bool> mp;
    
    bool dfs(string &word) {
        int n = word.size();
        
        for(int i = 1; i < n; i++) {
            string suff = word.substr(0, i);
            string pref = word.substr(i, n - i);
            
            if(mp.find(suff) != mp.end() && (mp.find(pref) != mp.end() || dfs(pref))) {
                return true;
            }
            //if(mp.find(suff)!=mp.end() && (mp.find(pref)!=mp.end()||check(pref))) return true;
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        for(auto it : words) {
            mp[it] = true;
        }
        
        for(auto it : words) {
            if(dfs(it)) {
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};