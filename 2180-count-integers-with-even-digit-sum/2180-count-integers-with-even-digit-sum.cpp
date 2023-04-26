class Solution {
public:
    int countEven(int num) {
        int currSum = 0;
        int temp = num; 
        
        while(num != 0) {
            currSum += num % 10;
            num /= 10;
        }
        
        if(currSum % 2 != 0) {
            return (temp - 1) / 2;
        }
        
        return temp / 2;
    }
};