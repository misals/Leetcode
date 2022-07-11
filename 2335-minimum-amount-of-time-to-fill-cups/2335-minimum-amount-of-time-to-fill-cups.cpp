class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        int a = amount[0];
        int b = amount[1];
        int c = amount[2];
        
        int ans = 0;
        while(a != 0 && b != 0 && c != 0) {
            if((a+b) >= (b+c)) {
                a--;
                b--;
            } 
            else {
                b--;
                c--;
            }
            ans++;
        }
        ans += max({a,b,c});
        return ans;
    }
};