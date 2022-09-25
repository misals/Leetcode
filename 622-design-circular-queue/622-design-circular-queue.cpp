class MyCircularQueue {
public:
    int len = 0;
    int front = 0;
    int rear = 0;
    vector<int> q;
    int sz = 0;
    
    MyCircularQueue(int k) {
        sz = k;
        front = 0;
        rear = 0;
        q.assign(k, -1);
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        len++;
        q[rear] = value;
        rear++;
        rear %= sz;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        len--;
        q[front] = -1;
        front = (front + 1) % sz;
        return true;
    }
    
    int Front() {
        if(isEmpty()) {
            return -1;
        }
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) {
            return -1;
        }
        int ind = rear - 1;
        if(ind < 0) {
            ind += sz;
        }
        return q[ind];
    }
    
    bool isEmpty() {
        if(len == 0) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(len == sz) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */