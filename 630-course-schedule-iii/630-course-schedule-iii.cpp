class Solution {
public:
    struct compare {
        bool operator() (const vector<int> &i, const vector<int> &j) {
            return i[1] < j[1];
        }
    };
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), compare());
        int total_duration = 0;
        priority_queue<int> pq;
        
        int n = courses.size();
        
        for(int i = 0; i < n; i++) {
            int curr_duration = courses[i][0];
            int end_time = courses[i][1];
            
            total_duration += curr_duration;
            
            pq.push(curr_duration);
            
            if(total_duration > end_time) {
                total_duration -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};