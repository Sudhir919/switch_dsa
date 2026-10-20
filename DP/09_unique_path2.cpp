//********************** Using Recursion **********************


class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid) {
        // Out of bounds
        if (i < 0 || j < 0) {
            return 0;
        }

        // Obstacle
        if (grid[i][j] == 1) {
            return 0;
        }

        // Starting cell
        if (i == 0 && j == 0) {
            return 1;
        }

        int up = solve(i - 1, j, grid);
        int left = solve(i, j - 1, grid);

        return up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return solve(m - 1, n - 1, obstacleGrid);
    }
};

	
//******************** Using DP (Memorization ) **********************
	

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        // Out of bounds
        if (i < 0 || j < 0) {
            return 0;
        }

        // Obstacle
        if (grid[i][j] == 1) {
            return 0;
        }

        // Starting cell
        if (i == 0 && j == 0) {
            return 1;
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = solve(i - 1, j, grid, dp);
        int left = solve(i, j - 1, grid, dp);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, obstacleGrid, dp);
    }
};
