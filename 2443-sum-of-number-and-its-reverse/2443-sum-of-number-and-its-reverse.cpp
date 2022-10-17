class Solution {
public:
    bool sumOfNumberAndReverse(int nums) {
        for(int i=0;i<=nums;++i){
            //get the current value and is revers
            string temp = to_string(i);
            reverse(temp.begin(),temp.end());
            int val = stoi(temp);
            val += i;
            if(val == nums)return true;
        }
        return false;
    }
};