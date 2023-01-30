class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        map<long long, int> mp1, mp2;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i = 0; i < n1; i++) {
            long long temp = nums1[i];
            mp1[temp * temp]++;
        }
        
        for(int i = 0; i < n2; i++) {
            long long temp = nums2[i];
            mp2[temp * temp]++;
        }
        
        int ans = 0;
        for(int i = 0; i < n1; i++) {
            for(int j = i + 1; j < n1; j++) {
                long long val1 = nums1[i];
                long long val2 = nums1[j];
                long long val = val1 * val2;
                if(mp2.find(val) != mp2.end()) {
                    ans += mp2[val];
                }
            }
        }
        
        for(int i = 0; i < n2; i++) {
            for(int j = i + 1; j < n2; j++) {
                long long val1 = nums2[i];
                long long val2 = nums2[j];
                long long val = val1 * val2;
                if(mp1.find(val) != mp1.end()) {
                    ans += mp1[val];
                }
            }
        }
        
        return ans;
    }
};