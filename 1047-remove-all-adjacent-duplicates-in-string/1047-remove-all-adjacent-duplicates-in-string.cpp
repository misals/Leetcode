class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        stack<char> st;
        int n = s.size();
        
        for(int i = 0; i < n ; i++) {
            if(st.empty()) {
                st.push(s[i]);
            }
            else {
                char ch = st.top();
                if(ch == s[i]) {
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};