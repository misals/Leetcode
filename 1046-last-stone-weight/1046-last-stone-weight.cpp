class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(auto &it : stones) {
            pq.push(it);
        }
        
        while(pq.size() >= 2) {
            int val1 = pq.top();
            pq.pop();
            int val2 = pq.top();
            pq.pop();
            
            if(val1 == val2) {
                continue;
            }
            pq.push(abs(val1-val2));
        }
        return pq.size() >=1 ? pq.top() : 0;
    }
};