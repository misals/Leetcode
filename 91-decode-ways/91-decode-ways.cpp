class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        
        int n = s.size();
        int a=1, b=1, c=0;
        
        for(int i=2;i<=n;i++){
            int d = s[i-1]-'0';
            int dd = 10*(s[i-2]-'0') + (s[i-1]-'0');
            
            if(1<=d && d<=9)
                c = b;
            if(10<=dd && dd<=26)
                c += a;
            
            a=b;
            b=c;
            c=0;
        }
        
        return b;
    }
};