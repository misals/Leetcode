class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        priority_queue<long> pq;
        long totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum += target[i];
            pq.push(target[i]);
        }
        
        while(!pq.empty()) {
            long maxi = pq.top();
            pq.pop();
            totalSum -= maxi;
            
            if(maxi == 1 || totalSum == 1) {
                return true;
            }
            if(maxi < totalSum || totalSum == 0 || maxi % totalSum == 0) {
                return false;
            }
            maxi %= totalSum;
            totalSum += maxi;
            pq.push(maxi);
        }
        return true;
    }
};