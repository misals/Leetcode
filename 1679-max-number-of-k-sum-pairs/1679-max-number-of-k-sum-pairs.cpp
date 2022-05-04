class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        int ans = 0;
        for(auto it : mp)
        {
            int num = k - it.first;
            if(num * 2 == k)
            {
                ans = ans + it.second / 2;
            }
            else if(mp.find(num) != mp.end())
            {
                ans = ans + min(it.second, mp[num]);
                mp.erase(num);
            }
        }
        return ans;
    }
};