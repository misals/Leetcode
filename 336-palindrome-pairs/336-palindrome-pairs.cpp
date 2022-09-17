class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0;
        int high = s.size() - 1;
        while(low <= high) {
            if(s[low++] != s[high--]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> ans;
        
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            string s = words[i];
            reverse(s.begin(), s.end());
            mp[s] = i;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= words[i].size(); j++) {
                string st1 = words[i].substr(0,j);
                string st2 = words[i].substr(j);
                
                if(mp.count(st1) && isPalindrome(st2) && mp[st1] != i) {
                    ans.push_back({i, mp[st1]});
                }
                
                if(!st1.empty() && mp.count(st2) && isPalindrome(st1) && mp[st2] != i) {
                    ans.push_back({mp[st2], i});
                }
            }
        }
        return ans;
    }
};