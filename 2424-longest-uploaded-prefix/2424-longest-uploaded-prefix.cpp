class LUPrefix {
public:
    vector<bool> v;
    int size, i;
    LUPrefix(int n) {
        size = n;
        i = 0;
        v.resize(n + 1, false);
    }
    
    void upload(int video) {
        v[video] = true;
        while(i < size && v[i + 1] == true) {
            i++;
        }
    }
    
    int longest() {
        return i;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */