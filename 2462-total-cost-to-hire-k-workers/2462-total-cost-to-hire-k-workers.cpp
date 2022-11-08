class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>,greater<int>> pq1, pq2;
        
        int low = 0;
        int high = costs.size() - 1;
        long long ans = 0;
        
        int cnt = 0;
        
        while(cnt < k) {
            while(pq1.size() < candidates && low <= high) pq1.push(costs[low++]);
            while(pq2.size() < candidates && high >= low) pq2.push(costs[high--]);
            
            int a = INT_MAX;
            int b = INT_MAX;
            
            if(pq1.size() > 0) {
                a = pq1.top();
            }
            if(pq2.size() > 0) {
                b = pq2.top();
            }
            
            if(a <= b) {
                ans += a;
                pq1.pop();
            }
            else {
                ans += b;
                pq2.pop();
            }
            cnt++;
        } 
        return ans;
    }
};