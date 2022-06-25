class Solution {
public:
    bool isRobotBounded(string instructions) {
        int n = instructions.size();
        char curr_dir = 'N';
        int x = 0, y = 0;
        
        for(int i = 0; i < n; i++) {
            if(instructions[i] == 'G') {
                y += (curr_dir == 'N' ? 1 : 0);
                y += (curr_dir == 'S' ? -1 : 0);
                x += (curr_dir == 'E' ? 1 : 0);
                x += (curr_dir == 'W' ? -1 : 0);
            }
            else {
                char incoming_dir = instructions[i];
                if(curr_dir == 'N') {
                    curr_dir = (incoming_dir == 'L' ? 'W' : 'E');
                }
                else if(curr_dir == 'S') {
                    curr_dir = (incoming_dir == 'L' ? 'E' : 'W');
                }
                else if(curr_dir == 'E') {
                    curr_dir = (incoming_dir == 'L' ? 'N' : 'S');
                }
                else if(curr_dir == 'W') {
                    curr_dir = (incoming_dir == 'L' ? 'S' : 'N');
                }
            }
        }
        if(x == 0 && y == 0 || curr_dir != 'N') 
            return true;
        return false;
    }
};