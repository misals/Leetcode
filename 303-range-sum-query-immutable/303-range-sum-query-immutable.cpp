class NumArray {
public:
    vector<long long> pref;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pref = vector<long long>(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        right++;
        left++;
        return pref[right] - pref[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */