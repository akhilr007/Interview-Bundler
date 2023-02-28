class UnionFind{
public:
    vector<int> size, parent;
    UnionFind(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int findUltimateParent(int node){
        if(node == parent[node])
            return node;
        
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v){

        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        if(parentU == parentV) return;

        if(size[parentU] < size[parentV]){
            parent[parentU] = parentV;
            size[parentV] += parentU;
        }
        else{
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
};

class Solution{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){

        int n = accounts.size();
        UnionFind uf(n);

        // map mails to node
        unordered_map<string, int> mailsToNode;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){

                string mail = accounts[i][j];

                if(mailsToNode.find(mail) == mailsToNode.end()){
                    mailsToNode[mail] = i;
                }
                else{
                    uf.unionBySize(i, mailsToNode[mail]);
                }
            }
        }

        vector<string> mergedMails[n];
        for(auto it: mailsToNode){
            string mail = it.first;
            int node = uf.findUltimateParent(it.second);

            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergedMails[i].size() == 0) continue;

            sort(begin(mergedMails[i]), end(mergedMails[i]));

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto mail: mergedMails[i]){
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};