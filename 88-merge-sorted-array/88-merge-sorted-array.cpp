class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int high = nums1.size() - 1;
        m--;
        n--;
        
        while(m >= 0 && n >= 0) {
            if(nums1[m] > nums2[n]) {
                nums1[high] = nums1[m];
                m--;
                high--;
            } else {
                nums1[high] = nums2[n];
                n--;
                high--;
            }
        }
        while(n >= 0) {
            nums1[high] = nums2[n];
            high--;
            n--;
        }
    }
};