class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        map<char,int> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        vector<pair<int,char>> v;
        for(auto it : mp) {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end());
        
        string ans;
        
        for(int i = v.size() - 1; i >= 0; i--) {
            int num = v[i].first;
            while(num--) {
                ans.push_back(v[i].second);
            }
        }
        
        return ans;
    }
};