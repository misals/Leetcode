class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
    vector<string> ans;
    if(n == 0){
        return ans; 
    }
    int st = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i]-1 != nums[i-1]){
            if(st != nums[i-1])
            ans.push_back(to_string(st)+"->"+to_string(nums[i-1]));
            else
            ans.push_back(to_string(st));
            st = nums[i]; 
        }
    }
    if(st != nums[n-1])
            ans.push_back(to_string(st)+"->"+to_string(nums[n-1]));
            else
            ans.push_back(to_string(st));
    return ans;
    }
};