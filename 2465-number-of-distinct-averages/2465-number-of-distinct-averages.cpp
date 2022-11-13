class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size() - 1;
        
        set<double> s;
        
        while(low < high) {
            //cout << (double)(nums[low] + nums[high]) / 2 << " ";
            s.insert((double)(nums[low++] + nums[high--]) / 2);
        }
        return s.size();
    }
};