class Solution {
public:
    int partitionString(string s) {
        int cnt = 0;
        
        map<char, int> mp;
        
        for(auto &it : s) {
            if(mp.find(it) != mp.end()) {
                cnt++;
                mp.clear();
            }
            mp[it]++;
        }
        if(mp.size() > 0) cnt++;
        return cnt;
    }
};