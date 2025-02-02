class StockSpanner {
public:
    stack<pair<int, int>> st;  // Stack to store {price, span}
    
    StockSpanner() {
        // No initialization needed since the stack is empty initially
    }
    
    int next(int price) {
        int span = 1;  
        
        // Pop elements while the stack is not empty and the top price is <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;  // Accumulate span
            st.pop();
        }
        
        // Push the current price along with its computed span
        st.push({price, span});

        return span;
    }
};

/**
 * Usage:
 * StockSpanner* obj = new StockSpanner();
 * int result = obj->next(price);
 */
