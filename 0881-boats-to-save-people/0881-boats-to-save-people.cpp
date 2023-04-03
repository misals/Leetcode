class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt = 0;
        int low = 0;
        int high = people.size() - 1;
        sort(people.begin(), people.end());
        
        long long sum = 0;
        
        while(low <= high) {
            
            if(people[low] + people[high] <= limit) {
                high--;
                low++;
            }
            else {
                high--; 
            }
            cnt++;
        }
        
        
        return cnt;
    }
};