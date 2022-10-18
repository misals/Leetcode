class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        n--;
        while(n > 0) {
            string temp = s;
            int sz = temp.size();
            
            string str = "";
            
            for(int i = 0; i < sz; i++) {
                int cnt = 1;
                int j = i + 1;
                while(j < sz && temp[j] == temp[i]) {
                    cnt++;
                    j++;
                }
                str += to_string(cnt);
                str += temp[i];
                i = j - 1;
                
                s = str;
            }
            n--;
        }
        return s;
    }
};