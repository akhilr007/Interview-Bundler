int Solution::isValid(string s) {

    stack<char> st;

    for(int i=0; i<s.length(); i++){

        char ch = s[i];

        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else if(ch == ')' || ch == ']' || ch == '}'){

            if(ch == ')'){
                if(st.size() == 0 || st.top() != '(') return false;
            }
            else if(ch == '}'){
                if(st.size() == 0 || st.top() != '{') return false;
            }
            else if(ch == ']'){
                if(st.size() == 0 || st.top() != '[') return false;
            }

            st.pop();
        }
    }

    return st.size() == 0 ? true : false;
}