//************** Using Recursion *************


class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid) {
        // Out of bounds
        if (i < 0 || j < 0) {
            return INT_MAX;
        }

        // Starting cell
        if (i == 0 && j == 0) {
            return grid[0][0];
        }

        int up = solve(i - 1, j, grid);
        int left = solve(i, j - 1, grid);

        return grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return solve(m - 1, n - 1, grid);
    }
};
	
	
	//********************** Using DP (Memorization) *****************
	
	
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        // Out of bounds
        if (i < 0 || j < 0) {
            return 1e9;
        }

        // Starting cell
        if (i == 0 && j == 0) {
            return grid[0][0];
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = solve(i - 1, j, grid, dp);
        int left = solve(i, j - 1, grid, dp);

        return dp[i][j] =
            grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, grid, dp);
    }
};
