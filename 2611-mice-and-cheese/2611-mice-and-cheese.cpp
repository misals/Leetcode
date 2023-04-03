class Solution {
public:
    int miceAndCheese(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++) {
            v.push_back({a[i] - b[i], i});
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        int ans = 0;
        for(int i = 0; i < k; i++) {
            ans += a[v[i].second];
        }
        for(int i = k; i < n; i++) {
            ans += b[v[i].second];
        }
        return ans;
    }
};