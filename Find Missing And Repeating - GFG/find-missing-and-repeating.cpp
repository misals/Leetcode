// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int x = 0;
        for(int i = 0; i < n; i++) {
            x ^= arr[i];
            x ^= (i+1);
        }
        int setBit = x & ~(x - 1);
        int a = 0;
        int b = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j] & setBit) {
                a ^= arr[j];
            } else {
                b ^= arr[j];
            }
            
            if((j + 1) & setBit) {
                a ^= (j+1);
            } else {
                b ^= (j+1);
            }
        }
        for(int i = 0; i < n; i++) {
            if(a == arr[i]) {
                break;
            }
            if(b == arr[i]) {
                int temp = a;
                a = b;
                b = temp;
                break;
            }
        }
        int* res;
        res[0] = a;
        res[1] = b;
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends