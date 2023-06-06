class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        map<int, int> mp;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int i = 1; i < n; i++) {
            int val = arr[i] - arr[i-1];
            mp[val]++;
        }
        return mp.size() == 1 ? true : false;
    }
};