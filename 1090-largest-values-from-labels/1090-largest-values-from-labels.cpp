class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b) {
        return a.first > b.first;
    }
    
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> v;
        int n = values.size();
        
        for(int i = 0; i < n; i++) {
            v.push_back({values[i], labels[i]});
        }
        
        sort(v.begin(), v.end(), comp);
        //for(int i = 0; i < n; i++) cout << v[i].first << " " << v[i].second << endl;
        
        map<int, int> mp;
        
        int ans = 0;
        int i = 0;
        
        while(numWanted > 0 && i < n) {
            if(mp[v[i].second] < useLimit) {
                ans += v[i].first;
                mp[v[i].second]++;
                numWanted--;
            }
            i++;
        }
        return ans;
        
    }
};