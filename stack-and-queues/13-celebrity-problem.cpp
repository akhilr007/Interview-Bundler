class Solution {
public:
    int celebrityProblem(vector<vector<int>> &m, int n){

        stack<int> st;

        // assume all are celebrity
        for(int i=0; i<m.size(); i++) st.push(i);

        // we will run till we only have one celebrity
        while(st.size()>1){

            int i=st.top();
            st.pop();

            int j=st.top();
            st.pop();

            if(m[i][j] == 1){
                // if i knows j -> then i will not be a celebrity
                // so we can push j back to stack in the contention to find our celebrity
                st.push(j);
            }
            else if(m[j][i] == 1){
                // if j knows i -> then j will not be celebrity
                // so we can push i back to stack in the contention to find our celebrity
                st.push(i);
            }
        }

        int potentialCelebrity = st.top();

        for(int i=0; i<m.size(); i++){
            if(i == potentialCelebrity) continue;

            // if i dont know potentialCelebrity or potentialCelebrity knows i it means
            // potentialCelebrity is not our celebrity
            if(m[i][potentialCelebrity] == 0 || m[potentialCelebrity][i] == 1){
                return -1;
            }
        }

        return potentialCelebrity;
    }
};