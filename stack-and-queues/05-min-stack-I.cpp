class MinStack {
private:
    stack<int> st;
    stack<int> mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        st.push(val);

        if(mini.size() == 0) mini.push(val);
        else{
            if(val <= mini.top()) mini.push(val);
        }
    }
    
    void pop() {
        
        if(st.size() == 0) return;

        int minEl = mini.top();

        if(minEl == st.top()){
            st.pop();
            mini.pop();
        }
        else st.pop();
        
    }
    
    int top() {
        if(st.size() == 0) return -1;
        return st.top();
    }
    
    int getMin() {
        if(mini.size() == 0) return -1;
        return mini.top();
    }
};
