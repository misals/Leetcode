class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mp;
        map<int,int> freq;
        
        for(auto it : arr) {
            mp[it]++;
        }
        for(auto it : mp) {
            if(freq.find(it.second) != freq.end()) {
                return false;
            }
            freq[it.second] = 1;
        }
        return true;
    }
};