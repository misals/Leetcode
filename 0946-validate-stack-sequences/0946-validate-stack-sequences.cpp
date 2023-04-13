class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int m = popped.size();
        
        int i = 1;
        int j = 0;
        
        stack<int> st;
        st.push(pushed[0]);
        
        while(!st.empty()) {
            if(st.top() == popped[j]) {
                st.pop();
                j++;
                
                if(st.empty()) {
                   if(i == n) {
                        break;
                    }
                    st.push(pushed[i]);
                i++; 
                }
            }
            else {
                if(i == n) {
                    break;
                }
                st.push(pushed[i]);
                i++;
            }
        }
        if(j == m) {
            return true;
        }
        
        return false;
    }
};