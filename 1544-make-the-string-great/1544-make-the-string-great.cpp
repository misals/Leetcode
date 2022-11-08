class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string str;
        stack<char> st;
        
        for(int i = 0; i < n ; i++) {
            if(st.empty()) {
                st.push(s[i]);
            }
            else {
                char ch = st.top();
                if(s[i] >= 'a' && s[i] <= 'z' && ch >= 'A' && ch <= 'Z') {
                    char ch1 = ch + 32;
                    if(ch1 == s[i]) {
                        st.pop();
                    }
                    else {
                        st.push(s[i]);
                    }
                }
                else if(s[i] >= 'A' && s[i] <= 'Z' && ch >= 'a' && ch <= 'z') {
                    char ch1 = s[i] + 32;
                    if(ch == ch1) {
                        st.pop();
                    }
                    else {
                        st.push(s[i]);
                    }
                }
                else {
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};