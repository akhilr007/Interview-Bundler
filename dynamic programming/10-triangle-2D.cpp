class Solution{
public:
	// time complexity -> O(2 ^ (1 + 2 + 3 .... N))
	// space complexity -> O( N )
	int utilRec(int i, int j, vector<vector<int>>& triangle, int n){

		if( i == n-1)
			return triangle[i][j];

		int move_down = triangle[i][j] + utilRec(i+1, j, triangle, n);
		int move_diagonal = triangle[i][j] + utilRec(i+1, j+1, triangle, n);

		return min(move_down, move_diagonal);
	}

	// time complexity -> O(N * N)
	// space complexity -> O(N * N) + O(N)
	int t[201][201]; // make it -1 using memset(t, -1, sizeof t)
	int utilMem(int i, int j, vector<vector<int>>& triangle, int n){

		if( i == n-1)
			return triangle[i][j];
		if(t[i][j] != -1)
			return t[i][j];

		int move_down = triangle[i][j] + utilMem(i+1, j, triangle, n);
		int move_diagonal = triangle[i][j] + utilMem(i+1, j+1, triangle, n);

		return t[i][j] = min(move_down, move_diagonal);
	}

	// time complexity -> O(N * N)
	// space complexity -> O( N * N)
	int utilTab(vector<vector<int>> & triangle){

		int n = triangle.size();

		vector<vector<int>> dp(n, vector<int> (n, 0));
		// base case -> if( i == n -1) return triangle[n-1][j]
		for(int j=0; j<n; j++)
			dp[n-1][j] = triangle[n-1][j];

		for(int i=n-2; i>=0; i--){

			for(int j=i; j>=0; j--){

				int move_down = triangle[i][j] + dp[i+1][j];
				int move_diagonal = triangle[i][j] + dp[i+1][j+1];

				dp[i][j] = min(move_down, move_diagonal);

			}
		}

		return dp[0][0];
	}

	// most optimal
	// time complexity -> O(N * N)
	// space complexity -> O(N)
	int minimumTotal(vector<vector<int>>& triangle){

		int n = triangle.size();
		
		vector<int> front(n, 0), cur(n, 0);

		for(int j=0; j<n; j++)
			front[j] = triangle[n-1][j];

		for(int i=n-2; i>=0; i--){

			for(int j=i; j>=0; j--){

				int move_down = triangle[i][j] + front[j];
				int move_diagonal = triangle[i][j] + front[j+1];

				cur[j] = min(move_down, move_diagonal);

			}

			front = cur;
		}

		return front[0]; 

	}
};