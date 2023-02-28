class MinStack {
private:
    stack<long long> st;
    long long minEl;
public:
    MinStack() {
        
    }
    
    void push(int val) {

        if(st.size() == 0){
            st.push(val);
            minEl = val;
        }
        else if(st.size() >= val){
            st.push(val);
        }
        else{
            st.push(val + val - minEl);
            minEl = val;
        }
        
    }
    
    void pop() {

        if(st.size() == 0) return;
        else{
            if(st.top() >= minEl){
                st.pop();
            }
            else{
                minEl = 2*minEl - st.top();
                st.pop();
            }
        }
        
    }
    
    int top() {
        
        if(st.size() == 0) return -1;
        else{
            if(st.top() >= minEl){
                return st.top();
            }
            else{
                return minEl;
            }
        }
    }
    
    int getMin() {
        if(st.size() == 0) return -1;
        return minEl;
    }
};
