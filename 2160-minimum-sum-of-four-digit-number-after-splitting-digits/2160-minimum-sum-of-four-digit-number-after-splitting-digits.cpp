class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        while(num != 0) {
            v.push_back(num % 10);
            num /= 10;
        }
        sort(v.begin(), v.end());
        
        return 10*v[0] + v[2] + 10 * v[1] + v[3];
    }
};