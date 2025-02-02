class MyStack {
public:
    queue<int> q;

 void push(int x) {
        int s = q.size();
        q.push(x);
        // Rotate the queue to make the last pushed element the front

        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }

    }
    
    
    int pop() {
        if (!q.empty()) {

            int topElement = q.front(); // Get the top element
            q.pop();  // Remove the top element
            return topElement;
        }

        return -1; // Return -1 or throw an exception if the stack is empty
    }
    
    int top() {

        if (!q.empty()) {
            return q.front(); // Return the top element
        }
        
        return -1; // Return -1 or throw an exception if the stack is empty
    }
    
    bool empty() {
        return q.empty(); // Check if the queue (stack) is empty
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