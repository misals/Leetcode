class Solution {
public:
    bool check(int x,vector<int> price,int k){
        int j=0;
        int len=1;
        for(int i=1;i<price.size();i++){
            if(price[i]-price[j]>=x){
                len++;
                j=i;
            }
        }
        if(len>=k){
            return 1;
        }
        return 0;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        
        int n=price.size();
        int l=0;
        int r=price[n-1]-price[0];
        int ans=0;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(check(mid,price,k)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        
        return ans;
    }
};