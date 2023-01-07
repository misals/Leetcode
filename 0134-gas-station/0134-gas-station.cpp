class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sumGas = 0;
        int sumCost = 0;
        
        for(int i = 0; i < n; i++) {
            sumGas += gas[i];
            sumCost += cost[i];
        }
        
        if(sumGas < sumCost) return -1;
        
        int ind = 0;
        int currFuel = 0;
        for(int i = 0; i < n; i++) {
            currFuel += gas[i];
            currFuel -= cost[i];
            
            if(currFuel < 0) {
                ind = i + 1;
                currFuel = 0;
            }
        }
        return ind;
        
    }
};