class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second; 
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int, int>> nums;
        int n = pairs.size();
        for(int i = 0; i < n; i++) {
            nums.push_back({pairs[i][0], pairs[i][1]});
        }
        
        sort(nums.begin(), nums.end(), comp);
        int cnt = 1;
        int end = nums[0].second;
        
        for(int i = 1; i < n; i++) {
            if(nums[i].first > end) {
                cnt++;
                end = nums[i].second;
            }
        }
        
        return cnt;
    }
};