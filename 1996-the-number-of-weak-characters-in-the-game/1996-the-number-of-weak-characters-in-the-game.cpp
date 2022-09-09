class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0] != b[0]){
            return a[0] > b[0];
        }
        return a[1] < b[1];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        map<int, int> mp;
        int n = properties.size();
        
        sort(properties.begin(), properties.end(), comp);
        
        int maxi = 0;
        int ans = 0;
        
        for(auto it : properties) {
            if(maxi > it[1]) {
                ans++;
            }
            else {
                maxi = it[1];
            }
        }
        return ans;
    }
};