string Solution::solve(string s) {

    string res="";

    queue<char> q;
    int hash[26] = {0};

    for(auto& ch : s){

        q.push(ch);
        hash[ch-'a']++;

        while(!q.empty() && v[q.front()-'a'] > 1) q.pop();

        if(q.size() == 0){
            res ++ "#";
        }
        else{
            res += q.front();
        }
    }

    return res;
}