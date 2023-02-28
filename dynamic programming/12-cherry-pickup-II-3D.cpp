class Solution {
public:
    // time complexity -> O(3^n + 3^n)
    // space complexity -> O(n)
    int utilRec(int i, int j1, int j2, vector<vector<int>>& grid, int n, int m){

        if(j1<0 || j2<0 || j1>=m || j2>=m)
            return -1e8;
        
        // base case
        if(i == n-1){

            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        // explore all the paths
        int maxi = 0;
        for(int dj1=-1; dj1<=1; dj1++){

            for(int dj2=-1; dj2<=1; dj2++){

                int value = 0;
                if(j1 == j2)
                    value = grid[i][j1];
                else    
                    value = grid[i][j1] + grid[i][j2];
                
                value += utilRec(i+1, j1+dj1, j2+dj2, grid, n, m);

                maxi = max(maxi, value);
            }
        }

        return maxi;
    }

    // time complexity -> O(n * m * m)
    // space complexity -> O(n) + O(n * m * m)
    int t[101][101][101];
    int utilMem(int i, int j1, int j2, vector<vector<int>>& grid, int n, int m){

        if(j1<0 || j2<0 || j1>=m || j2>=m)
            return -1e8;
        
        // base case
        if(i == n-1){

            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if(t[i][j1][j2] != -1)
            return t[i][j1][j2];

        // explore all the paths
        int maxi = 0;
        for(int dj1=-1; dj1<=1; dj1++){

            for(int dj2=-1; dj2<=1; dj2++){

                int value = 0;
                if(j1 == j2)
                    value = grid[i][j1];
                else    
                    value = grid[i][j1] + grid[i][j2];
                
                value += utilMem(i+1, j1+dj1, j2+dj2, grid, n, m);

                maxi = max(maxi, value);
            }
        }

        return t[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid){

        int n = grid.size();
        int m = grid[0].size();

        memset(t, -1, sizeof t);

        return utilMem(0, 0, n-1, grid, n, m);
    }
};