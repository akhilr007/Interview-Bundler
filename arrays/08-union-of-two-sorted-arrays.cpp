class Solution {
public:
    // brute force
    // time complexity -> O(n+mlog(n+m)) and space complexity -> O(n+m)
    vector<int> bruteForce(vector<int>& a, vector<int>& b){

        int n = a.size(), m = b.size();

        set<int> st;
        for(int i=0; i<n; i++)
            st.insert(a[i]);
        for(int i=0; i<m; i++)
            st.insert(b[i]);

        vector<int> Union;
        for(auto &x : st){
            Union.push_back(x);
        }

        return Union;
    }

    vector<int> findUnion(vector<int>& a, vector<int>& b){

        int n = a.size(), m = b.size();

        vector<int> Union;

        int i=0;
        int j=0;

        while(i<n && j<m){

            if(a[i] <= b[j]){

                if(Union.size() == 0 || Union.back() != a[i]){
                    Union.push_back(a[i]);
                }
                i++;
            }
            else{
                if(Union.size() == 0 || Union.back() != b[j]){
                    Union.push_back(b[j]);
                }
                j++;
            }
        }

        while(i<n){

            if(Union.back() != a[i]){
                Union.push_back(a[i]);
            }
            i++;
        }

        while(j<m){

            if(Union.back() != b[j]){
                Union.push_back(b[j]);
            }
            j++;
        }

        return Union;
        
    }
};