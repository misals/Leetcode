class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int cnt = 0;
        map<int, int> mp;
        for(auto it : tasks) {
            mp[it]++;
        }
        
        for(auto it : mp) {
            int val = it.second;
            int temp = 0;
            while(val >= 2 && val % 3 != 0) {
                temp++;
                val -= 2;
            }
            if(val % 3 == 0) {
                cnt += temp;
                cnt += val/3;
            }
            else {
                return -1;
            }
        }
        return cnt;
    }
};