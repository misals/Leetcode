class CustomStack {
public:
    int n, i = 0;
    vector<int> v;
    CustomStack(int maxSize) {
        n = maxSize;
        v.resize(n);
    }
    
    void push(int x) {
        if(i < n) {
            v[i] = x;
            i++;
        }
    }
    
    int pop() {
        if(i > 0) {
            i--;
            return v[i];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int j = 0; j < min(i, k); j++) {
            v[j] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */