class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int n = arr.length;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            int cnt = 0;
            for(int j = i; j < n; j++) {
                cnt++;
                sum += arr[j];
                if(cnt % 2 != 0) {
                    ans += sum;
                }
            }
        }
        return ans;
    }
}