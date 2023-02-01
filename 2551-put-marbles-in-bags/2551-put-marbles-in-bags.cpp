class Solution {
public:
    long long putMarbles(vector<int>& weight, int k) {
        vector<long long> v;
        int n = weight.size();
        long long s1 = weight[0] + weight[n-1];
        long long s2 = weight[0] + weight[n-1];
    
        for(int i = 1; i < n; i++) {
            v.push_back(weight[i] + weight[i-1]);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < k - 1; i++) {
            s1 += v[i];
        }
        reverse(v.begin(), v.end());
        for(int i = 0; i < k - 1; i++) {
            s2 += v[i];
        }
        return s2 - s1;
    }
};