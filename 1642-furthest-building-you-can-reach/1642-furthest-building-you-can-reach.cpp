class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        int i;
        for(i = 0; i < n - 1; i++) {
            if(heights[i+1] <= heights[i]) {
                continue;
            }
            
            int diff = heights[i+1] - heights[i];
            if(diff <= bricks) {
                bricks -= diff;
                pq.push(diff);
            } else if(ladders > 0) {
                if(pq.size() > 0) {
                    int num = pq.top();
                    if(num >= diff) {
                        bricks += num;
                        pq.pop();
                        pq.push(diff);
                        bricks -= diff;
                    }
                }
                ladders--;
            } else {
                break;
            }
        }
        return i;
    }
};