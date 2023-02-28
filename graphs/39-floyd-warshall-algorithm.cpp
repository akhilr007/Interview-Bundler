class Solution{
public:
    // time complexity -> O(n^3)
    void floydWarshall(vector<vector<int>> &matrix){

        int n = matrix.size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j){
                    matrix[i][j] = 0;
                    continue;
                }
                if(matrix[i][j] == -1) matrix[i][j] = (int)1e9;
            }
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){

                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == (int)1e9) matrix[i][j] = -1;
            }
        }
    }
}