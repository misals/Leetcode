class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int maxReach = startFuel;
        int index = 0;
        int cnt = 0;
        
        while(maxReach < target) {
            while(index < stations.size() && stations[index][0] <= maxReach) {
                pq.push(stations[index][1]);
                index++;
            }
            if(pq.empty()) {
                return -1;
            }
            cnt++;
            maxReach += pq.top();
            pq.pop();
        }
        
        return cnt;
    }
};