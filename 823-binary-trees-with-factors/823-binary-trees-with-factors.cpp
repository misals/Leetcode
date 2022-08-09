class Solution {
public:
    int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        map<int, long long> mp;
        
        for(int i = 0; i < n; i++) {
            mp[arr[i]] = 1;
        }
        sort(arr.begin(), arr.end());
        
        for(int i = 1; i < n; i++) {
            long long int count = 0;
            for(int j = 0; j < i; j++) {
                if(arr[i] % arr[j] == 0) {
                    auto it = mp.find(arr[i] / arr[j]);
                    auto it1 = mp.find(arr[j]);
                    
                    if(it != mp.end()) {
                        count += (it->second * it1->second);
                    }
                }
            }
            mp[arr[i]] += count;
        }
        long long int ans = 0;
        for(auto it : mp) {
            ans += it.second;
        }
        return ans % mod;
    }
};