class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        int count = 0;
        int n = arr.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        
        for (auto p : mp) {
          if ((!k && p.second > 1) || (k && mp.count(p.first + k))) 
              ++count;
        }
        
        return count;
    }
};