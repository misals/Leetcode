class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        
        while(target > 1 && maxDoubles > 0) {
            if(target % 2 == 0) {
                cnt++;
                target /= 2;
            }
            else {
                cnt += 2;
                target /= 2;
            }
            maxDoubles--;
        }
        
        cnt += (target - 1);
        return cnt;
    }
};