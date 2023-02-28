class Solution{
public:
// time complexity -> O(n * n!)
    unordered_set<int> cols, posDiag, negDiag;
    /*
    posDiagonal -> (row + col) since from left to right col increases while row decreases so (r+c) is constant
    negDiagonal -> (row - col) since from left to right col increase and row also increases
    */

    void solve(int row, vector<vector<char>>& board, vector<vector<string>>& ans, int n){

        if(row == n){

            vector<string> temp;
            for(auto b: board){
                string s(b.begin(), b.end());
                temp.push_back(s);
            }

            ans.push_back(temp);
            return;
        }
        
        for(int col=0; col<n; col++){
            if(cols.find(col) != cols.end() || posDiag.find(row+col) != posDiag.end() || negDiag.find(row-col) != negDiag.end()){
                continue;
            }

            cols.insert(col);
            negDiag.insert(row - col);
            posDiag.insert(row + col);
            board[row][col] = 'Q';

            solve(row+1, board, ans, n);

            cols.erase(col);
            negDiag.erase(row - col);
            posDiag.erase(row + col);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n){

        vector<vector<char>> board(n, vector<char> (n, '.'));
        vector<vector<string>> ans;

        solve(0, board, ans, n);
        return ans;
    }
};