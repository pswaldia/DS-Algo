class MinStack {
    stack<int> main;
    stack<int> track_min
public:
    /** initialize your data structure here. */
    MinStack() {
        // no requirement......
    }
    
    void push(int x) {
        if (main.size() == 0) {
            main.push(x);
            track_min.push(x);
        } else {
            main.push(x);
            if (x <= track_min.top()) {
                track_min.push(x);
            }
        }
    }
    
    void pop() {
        int x = main.top();
        main.pop(); // this will be performed always.....
        if (x == track_min.top()) {
            track_min.pop();  // this will be done only when the main's top will be equal to minn's top.
        }
        
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return track_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
