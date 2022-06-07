class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int,int> mp;
        int n = stones.size();
        
        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        vector<unordered_set<int>> jump(n, unordered_set<int>());
        if(stones[1] != 1) {
            return false;
        }
        if(n == 2) {
            return true;
        }
        jump[1].insert(1);
        
        for(int i = 1; i < n; i++) {
            unordered_set<int> possible;
            
            for(auto it : jump[i]) {
                if(it > 1) {
                    possible.insert(stones[i] + it - 1);
                }
                possible.insert(stones[i] + it);
                possible.insert(stones[i] + it + 1);
            }
            
            for(auto it : possible) {
                if(mp.find(it) == mp.end()) {
                    continue;
                }
                
                int index = mp[it];
                if(index == n - 1) {
                    return true;
                }
                int jumpLen = it - stones[i];
                jump[index].insert(jumpLen);
            }
        }
        return false;
    }
};