class MyStack {
public:
    queue<int> q;
    MyStack() {
        while(!q.empty()) q.pop();
    }
    
    void push(int x) {
        q.push(x);
        int n = q.size()-1;
        while(n--) {
            int x = q.front(); q.pop();
            q.push(x);
        }
    }
    
    int pop() {
        if(q.empty()) return -1;
        else {
            int ans = q.front();
            q.pop();
            return ans;
        }
    }
    
    int top() {
        if(q.empty()) return -1;
        else {
            return q.front();
        }
    }
    
    bool empty() {
        if(q.empty()) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */