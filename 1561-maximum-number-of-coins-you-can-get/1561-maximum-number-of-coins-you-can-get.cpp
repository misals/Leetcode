class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        
        int sum = 0;
        int i = n / 3;
        for(int j = i; j < n; j += 2) {
            sum += piles[j];
        }
        return sum;
    }
};