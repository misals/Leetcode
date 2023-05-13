class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> v(high+1,0);
        v[0] = 1;
        int mod = 1e9+7;
        int sum = 0;
        for(int i = 1; i <= high; i++){
            if(i>=zero){
                v[i] = (v[i]*1LL+v[i-zero])%mod;
            }if(i>=one){
                v[i] = (v[i]*1LL+v[i-one])%mod;
            }
            // cout<<v[i]<<" ";
            if(i>=low && i<=high){
                sum = (sum*1LL+v[i])%mod;
            }
        }
        return sum;
    }
};