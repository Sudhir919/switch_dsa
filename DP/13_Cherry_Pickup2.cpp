//**************** Recursion *******************

class Solution {
public:
    int rows, cols;

    int solve(int i, int j1, int j2,
              vector<vector<int>>& grid) {

        // Both robots must remain inside the grid
        if (j1 < 0 || j1 >= cols ||
            j2 < 0 || j2 >= cols) {
            return -1e8;
        }

        // Collect cherries from the current row
        int cherries = grid[i][j1];

        if (j1 != j2) {
            cherries += grid[i][j2];
        }

        // Last row: no more moves
        if (i == rows - 1) {
            return cherries;
        }

        int maxi = -1e8;

        // Try all 9 combinations of moves
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int next = solve(
                    i + 1, j1 + d1, j2 + d2, grid
                );

                maxi = max(maxi, next);
            }
        }

        return cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        return solve(0, 0, cols - 1, grid);
    }
};



//******************** DP(Memorization) *************************


class Solution {
public:
    int rows, cols;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j1, int j2,vector<vector<int>>& grid) {

        // Invalid column positions
        if (j1 < 0 || j1 >= cols ||
            j2 < 0 || j2 >= cols) {
            return -1e8;
        }

        // Cherries collected in the current row
        int cherries = grid[i][j1];

        if (j1 != j2) {
            cherries += grid[i][j2];
        }

        // Base case: last row
        if (i == rows - 1) {
            return cherries;
        }

        // Reuse the previously calculated answer
        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }

        int maxi = 0;

        // Try all 9 combinations
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {

                int next = solve(i + 1, j1 + d1,j2 + d2,grid );

                maxi = max(maxi, next);
            }
        }

        return dp[i][j1][j2] = cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        dp.assign(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));

        return solve(0, 0, cols - 1, grid);
    }
};

