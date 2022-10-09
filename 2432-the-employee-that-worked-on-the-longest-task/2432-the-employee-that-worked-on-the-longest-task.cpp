class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int resId;
        int startTime = 0;
        int maxTime = 0;
        int sz = logs.size();
        
        for(int i = 0; i < sz; i++) {
            int timeTaken = logs[i][1] - startTime;
            if(timeTaken >= maxTime) {
                if(timeTaken == maxTime) {
                    resId = min(resId, logs[i][0]);
                }
                else {
                    maxTime = timeTaken;
                    resId = logs[i][0];
                }
                
            }
            startTime = logs[i][1];
        }
        return resId;
    }
};