class Solution {
public:
    bool alreadyHappened(vector<int> &sides, int pos) {
        for(int i = 0; i < pos; i++) {
            if(sides[i] == sides[pos]) {
                return true;
            }
        }
        return false;
    }
    
    bool fun(int ind, int tar, vector<int> &matchsticks, vector<int> &sides) {
        if(ind == matchsticks.size()) {
            if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]) {
                return true;
            }
            return false;
        }
        for(int i = 0; i < 4; i++) {
            if(sides[i] + matchsticks[ind] > tar || alreadyHappened(sides, i)) {
                continue;
            }
            sides[i] += matchsticks[ind];
            if(fun(ind+1, tar, matchsticks, sides)) {
                return true;
            }
            sides[i] -= matchsticks[ind];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int n = matchsticks.size();
        for(int i = 0; i < n; i++) {
            sum += matchsticks[i];
        }
        if(sum % 4 != 0 || matchsticks[0] > sum / 4) {
            return false;
        } 
        int tar = sum / 4;
        
        vector<int> sides(4, 0);
        
        return fun(0, tar, matchsticks, sides);
    }
};