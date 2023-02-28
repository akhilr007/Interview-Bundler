class Solution{
public:
    string topologicalSort(unordered_map<char, unordered_set<char>>& adj, unordered_map<char, int>& indegree){

        priority_queue<char, vector<char>, greater<char>> pq;

        for(auto it: indegree){
            if(it.second == 0) pq.push(it.first);
        }

        int cnt=0;
        string ans="";
        while(!pq.empty()){
            
            char ch = pq.top();
            pq.pop();

            cnt++;
            ans += ch;

            if(adj.find(ch) != adj.end()){
                auto charSet = adj[ch];
                for(auto ch: charSet){
                    indegree[ch]--;
                    if(indegree[ch] == 0) pq.push(ch);
                }
            }
        }

        if(cnt == indegree.size()) return ans;
        return "";
    }

    string alienOrder(vector<string>& words){

        // creating an adjacency map
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        // make all the chars in indegree 0
        for(auto& word: words){
            for(auto& ch: word){
                indegree[ch] = 0;
            }
        }

        for(int i=0; i<words.size()-1; i++){

            string s1 = words[i];
            string s2 = words[i+1];

            bool flag = false;
            int len = min(s1.length(), s2.length());
            for(int p=0; p<len; p++){

                char ch1 = s1[p], ch2 = s2[p];

                if(ch1 != ch2){

                    if(adj.find(ch1) != adj.end()){

                        auto charSet = adj[ch1];
                        if(charSet.find(ch2) == charSet.end()){
                            charSet.insert(ch2);
                            adj[ch1] = charSet;
                            indegree[ch2]++;
                        }
                    }
                    else{
                        adj[ch1].insert(ch2);
                        indegree[ch2]++;
                    }

                    flag = true;
                    break;
                }
            }

            if(flag == false && (s1.length() > s2.length())) return "";
        }

        return topologicalSort(adj, indegree);

    }
};