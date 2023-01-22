class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        int n = nums1.size();
        long long up = 0;
        long long down = 0;
        
        if(k == 0) {
            for(int i = 0; i < n; i++) {
                if(nums1[i] != nums2[i]) {
                    return -1;
                }
            }
            return 0;
        }
        
        for(int i = 0; i < n; i++) {
            if(nums1[i] > nums2[i]) {
                int val = nums1[i] - nums2[i];
                if(val % k != 0) {
                    return -1;
                }
                up += (val / k);
            }
            else if(nums1[i] < nums2[i]) {
                int val = nums2[i] - nums1[i];
                if(val % k != 0) {
                    return -1;
                }
                down += (val / k);
            }
        }
        //cout << up << " " << down;
        if(up == down) {
            return up;
        }
        return -1;
    }
};