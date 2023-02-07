class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        map<int, int> mp;
        int ans = 0;
        int cnt = 0;
        int j = 0;
        
        for(int i = 0; i < n; i++) {
            mp[fruits[i]]++;
            
            if(mp.size() > 2) {
                while(mp.size() > 2) {
                    mp[fruits[j]]--;
                    if(mp[fruits[j]] == 0) {
                        mp.erase(fruits[j]);
                    }
                    j++;
                }
                int temp = i - (j - 1);
                ans = max(ans, temp);
                cnt = max(2, temp);
                
            }
            else {
                cnt++;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};