class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;
        priority_queue<int> pq;
        
        for(auto it : nums) {
            pq.push(it);
        }
        
        while(k--) {
            long long val = pq.top();
            pq.pop();
            sum += val;
            if(val % 3 == 0) {
                pq.push(val / 3);
            }
            else {
                pq.push((val/3) + 1);
            }
        }
        return sum;
    }
};