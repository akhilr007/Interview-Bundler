int Solution::braces(string s) {

    stack<char> st;

    for(auto& ch : s){

        if(ch == ')'){

            char top = st.top();
            st.pop();

            bool flag = true; // have redundant braces
            while(st.size() > 0 && top != '('){

                if(top == '+' || top == '-' || top == '/' || top == '*'){
                    flag = false;
                }

                top = st.top();
                st.pop();
            }

            if(flag == true) return true; // 

        }
        else st.push(ch);
    }

    return false;
}