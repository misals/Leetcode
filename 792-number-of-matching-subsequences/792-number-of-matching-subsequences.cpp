class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        map<char, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]].push_back(i);
        }
        int sz = words.size();
        
        int cnt = 0;
        for(int i = 0; i < sz; i++) {
            string temp = words[i];
            
            int latest = -1;
            for(int j = 0; j < temp.size(); j++) {
                auto it = upper_bound(mp[temp[j]].begin(), mp[temp[j]].end(), latest);
                if(it == mp[temp[j]].end()) {
                    break;
                }
                latest = *it;
                if(j == temp.size() - 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};