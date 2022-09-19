class Solution {
public:
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int count(string s) {
        string mm, dd;
        mm += s[0];
        mm += s[1];
        
        dd += s[3];
        dd += s[4];
        
        int m = stoi(mm);
        int d = stoi(dd);
        
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            cnt += month[i];
        }
        cnt += d;
        return cnt;
    }
    
    int countDaysTogether(string aA, string lA, string aB, string lB) {
        int arr1 = count(aA);
        int arr2 = count(aB);
        int lev1 = count(lA);
        int lev2 = count(lB);
        
        int arr = max(arr1, arr2);
        int lev = min(lev1, lev2);
        
        if(arr > lev) {
            return 0;
        }
        
        return lev - arr + 1;
    }
};