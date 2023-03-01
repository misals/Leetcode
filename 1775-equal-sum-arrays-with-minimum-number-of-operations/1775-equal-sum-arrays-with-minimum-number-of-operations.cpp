class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int n = nums1.size();
        int m = nums2.size();
        
        int sum1 = 0;
        int sum2 = 0;
        
        for(auto it : nums1) sum1 += it;
        for(auto it : nums2) sum2 += it;
        
        priority_queue<int> pq;
        
        if(sum1 >= sum2) {
            for(int i = 0; i < n; i++) {
                pq.push(nums1[i] - 1);
            }
            for(int i = 0; i < m; i++) {
                pq.push(6 - nums2[i]);
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                pq.push(6 - nums1[i]);
            }
            for(int i = 0; i < m; i++) {
                pq.push(nums2[i] - 1);
            }
        }
        int cnt = 0;
        int val = abs(sum1 - sum2);
        
        while(pq.top() > 0) {
            if(val <= 0) {
                return cnt;
            }
            cnt++;
            val -= pq.top();
            pq.pop();
        }
        return -1;
    }
};