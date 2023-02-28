int Solution::solve(string s) {

    stack<char> st;

    for(int i=0; i<s.length(); i++){

        if(s[i] == '(') st.push(s[i]);

        else if(s[i] == ')'){
            if(st.size() == 0 || st.top() != '(') return false;
            st.pop();
        }
    }

    return st.size() == 0 ? true : false;
    
    }