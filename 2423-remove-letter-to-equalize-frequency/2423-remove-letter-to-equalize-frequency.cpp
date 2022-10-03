class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.size();
        bool flag = true;
        map<char, int> mp;
        
        for(int i = 0; i < n; i++) {
            mp[word[i]]++;
        }
        vector<int> v;
        for(auto it : mp) {
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
       
        int sz = v.size();
        if(sz == 1) {
            return true;
        }
        if(v[0] == v[sz - 1] && v[0] == 1) return true;
        if(sz == 2) {
            if(v[0] == v[1]) {
                return false;
            }
            if(v[1] - v[0] == 1) {
                return true;
            }
            return false;
        }
        if(sz >= 3) {
            if(v[sz - 1] == v[sz - 2]) {
                v[0]++;
            }
            else {
                v[sz - 1]--;
            }
        }
        
        
        for(int i = 1; i < sz; i++) {
            if(v[i] != v[i-1]) {
                return false;
            }
        }
        return true;
        
    }
};