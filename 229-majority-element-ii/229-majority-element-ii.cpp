class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = -1;
        int ele2 = -1;
        int cnt1 = 0;
        int cnt2 = 0;
        
        for(auto it : nums) {
            if(it == ele1) {
                cnt1++;
            } else if(it == ele2) {
                cnt2++;
            } else if(cnt1 == 0) {
                ele1 = it;
                cnt1 = 1;
            } else if(cnt2 == 0) {
                ele2 = it;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1 = cnt2 = 0;
        for(int it : nums) {
            if(it == ele1) {
                cnt1++;
            } else if(it == ele2) {
                cnt2++;
            }
        }
        if(cnt1 > nums.size() / 3) {
            ans.push_back(ele1);
        }
        if(cnt2 > nums.size() / 3) {
            ans.push_back(ele2);
        }
        return ans;
    }
};