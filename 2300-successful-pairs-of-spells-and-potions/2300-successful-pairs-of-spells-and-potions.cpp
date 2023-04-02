class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        
        sort(potions.begin(), potions.end());
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            int low = 0;
            int high = m - 1;
            int ind = -1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                long long temp = (long)potions[mid] * (long)spells[i] ;
                
                if(temp >= success) {
                    ind = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            
            if(ind == -1) {
                ans.push_back(0);
            }
            else {
                ans.push_back(m - ind);
            }
        }
        return ans;
    }
};