class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == 'B') {
                if(st.empty()) {
                    st.push(s[i]);
                }
                else {
                    char ch = st.top();
                    if(ch == 'A') {
                        st.pop();
                    }
                    else {
                        st.push(s[i]);
                    }
                }
            }
            else if(s[i] == 'D') {
                if(st.empty()) {
                    st.push(s[i]);
                }
                else {
                    char ch = st.top();
                    if(ch == 'C') {
                        st.pop();
                    }
                    else {
                        st.push(s[i]);
                    }
                }
            }
            else {
                st.push(s[i]);
            }
        }
        return st.size();
    }
};