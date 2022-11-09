class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<pair<int, int>> st;
        int n = arr.size();
        vector<int> ans(n);
        
        ans[n-1] = 0;
        st.push({arr[n-1], n - 1});
        
        for(int i = n - 2; i >= 0; i--) {
            while(!st.empty() && st.top().first <= arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans[i] = 0;
            }
            else {
                ans[i] = st.top().second - i;
            }
            st.push({arr[i], i});
        }
        return ans;
        
    }
};