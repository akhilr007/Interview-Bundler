int Solution::evalRPN(vector<string> &s) {

    stack<int> st;

    for(int i=0; i<s.size(); i++){
        string ch = s[i];

        if(ch == "+" || ch == "*" || ch == "-" || ch == "/"){

            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            int val;
            if(ch == "+"){
                val = (a+b);
            }
            else if(ch == "-"){
                val = (a-b);
            }
            else if(ch == "*"){
                val = (a*b);
            }
            else{
                val = (a/b);
            }
            
            st.push(val);
            
        }
        else{
            st.push(stoi(ch));
        }
    }

    return st.top();
}