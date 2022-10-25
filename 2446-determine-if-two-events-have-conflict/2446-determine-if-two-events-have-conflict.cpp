class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int arr1[1441] = {0};
        int arr2[1441] = {0};
        
        int time1_start = ((event1[0][0] - '0') * 10 + (event1[0][1] - '0')) * 60;
        time1_start += (event1[0][3] - '0') * 10 + (event1[0][4] - '0');
        
        int time1_end = ((event1[1][0] - '0') * 10 + (event1[1][1] - '0')) * 60;
        time1_end += (event1[1][3] - '0') * 10 + (event1[1][4] - '0');
        
        cout << time1_start << " " << time1_end << endl;
        
        for(int i = time1_start; i <= time1_end; i++) {
            arr1[i] = 1;
        }
        
        int time2_start = ((event2[0][0] - '0') * 10 + (event2[0][1] - '0')) * 60;
        time2_start += (event2[0][3] - '0') * 10 + (event2[0][4] - '0');
        
        int time2_end = ((event2[1][0] - '0') * 10 + (event2[1][1] - '0')) * 60;
        time2_end += (event2[1][3] - '0') * 10 + (event2[1][4] - '0');
        
        for(int i = time2_start; i <= time2_end; i++) {
            arr2[i] = 1;
        }
        cout << time2_start << " " << time2_end << endl;
        for(int i = 0; i <= 1440; i++) {
            if(arr1[i] == 1 && arr2[i] == 1) return true;
        }
        
        return false;
    }
};