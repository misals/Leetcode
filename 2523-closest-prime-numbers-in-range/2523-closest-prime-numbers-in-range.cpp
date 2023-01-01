class Solution {
public:
    vector<int> solve(int left, int n) {
        vector<int> v;
        vector<int> ans(2, -1);
        bool is_prime[n + 1];
        memset(is_prime, true, sizeof(is_prime));

        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        for(int i = left; i <= n; i++) {
            if(is_prime[i]) {
                v.push_back(i);
            }
        }
        int sz = v.size();
        int mini = INT_MAX;
        for(int i = 1; i < sz; i++) {
            if(v[i] - v[i-1] < mini) {
                mini = v[i] - v[i-1];
                ans[0] = v[i-1];
                ans[1] = v[i];
            }
        }

        return ans;
     }
    vector<int> closestPrimes(int left, int right) {
        return solve(left, right);
    }
};