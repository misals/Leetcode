class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q;
    
    void push(int x) {
       q.push(x); 
        int n = q.size();
        for(int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int popEle = q.front();
        q.pop();
        return popEle;
    }
    
    int top() {
        int topEle = q.front();
        return topEle;
    }
    
    bool empty() {
        return q.empty();
    }
};