class MyCalendarThree {
public:
    map<int, int> mp;
    int maxCnt = 0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int cnt = 0;
        mp[start]++;
        mp[end]--;
        
        for(auto it : mp) {
            cnt += it.second;
            maxCnt = max(maxCnt, cnt);
        }
        
        return maxCnt;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */