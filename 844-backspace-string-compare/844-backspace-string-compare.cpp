class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '#')
                st1.push(s[i]);
            else
            {
                if(st1.size() > 0)
                    st1.pop();
            }
        } 
        for(int i = 0; i < t.size(); i++) {
            if(t[i] != '#')
                st2.push(t[i]);
            else
            {
                if(st2.size() > 0)
                    st2.pop();
            }
        } 
        string a = "";
        string b = "";
        while(!st1.empty())
        {
            a = a + st1.top();
            st1.pop();
        }
        while(!st2.empty())
        {
            b = b + st2.top();
            st2.pop();
        }
        return a == b;
        
    }
};