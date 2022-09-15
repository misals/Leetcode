class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> ans;
        if(n % 2 != 0) {
            return ans;
        }
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[changed[i]]++;
        }
        sort(changed.begin(), changed.end());
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(changed[i] == 0) {
                cnt++;
            }
            else if(mp[changed[i]] > 0) {
                if(mp[changed[i] * 2] > 0 ) {
                    ans.push_back(changed[i]);
                    mp[changed[i] * 2]--;
                    mp[changed[i]]--;
                }
                else if(changed[i] % 2 == 0 && changed[i] != 0) {
                    if(mp[changed[i] / 2] > 0 ) {
                        ans.push_back(changed[i] / 2);
                        mp[changed[i] / 2]--;
                        mp[changed[i]]--;
                    }
                }
            } 
        }
        vector<int> temp;
        if(cnt % 2 == 0) {
            cnt /= 2;
            while(cnt--) 
                ans.push_back(0);
        }
        else
            return temp;
        if(ans.size() == n / 2) {
            return ans;
        }
        return temp;
    }
};