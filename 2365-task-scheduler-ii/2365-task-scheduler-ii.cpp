class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day = 0;
        map<int, long long> mp;
        int n = tasks.size();
        
        for(int i = 0; i < n; i++) {
            if(mp.find(tasks[i]) == mp.end()) {
                day++;
                mp[tasks[i]] = day;
                continue;
            }
            long long lastDay = mp[tasks[i]];
            day = max(day + 1, lastDay + space + 1);
            mp[tasks[i]] = day;
        }
        return day;
    }
};