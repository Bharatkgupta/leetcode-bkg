class CustomStack {
    vector<int> stack;
    int size;
public:
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(stack.size() < size) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        if(stack.empty()) {
            return -1;
        }
        int temp = stack.back();
        stack.pop_back();
        return temp;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k && i<stack.size();i++) {
            stack[i] += val;
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