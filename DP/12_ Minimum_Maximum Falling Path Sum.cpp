/*

-->> Approach

i. represent in (i,j) form  -->> base case
ii. explore all path
iii. maxm of all paths


*/



//*************** Recursion *******************


class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Out of bounds
        if (j < 0 || j >= n) {
            return 10000000;
        }

        // Reached the last row
        if (i == n - 1) {
            return matrix[i][j];
        }

        int down = solve(i + 1, j, matrix);
        int left = solve(i + 1, j - 1, matrix);
        int right = solve(i + 1, j + 1, matrix);

        return matrix[i][j] + min({down, left, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = 10000000;

        // Try every starting column
        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, matrix));
        }

        return ans;
    }
}; 


// *********************** DP ( Memorization) ********************
															

class Solution {
public:
    int solve(int i, int j,
              vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {
        int n = matrix.size();

        // Out of bounds
        if (j < 0 || j >= n) {
            return 10000000;
        }

        // Reached the last row
        if (i == n - 1) {
            return matrix[i][j];
        }

        // Already calculated
        if (dp[i][j] != 10000000) {
            return dp[i][j];
        }

        int down = solve(i + 1, j, matrix, dp);
        int left = solve(i + 1, j - 1, matrix, dp);
        int right = solve(i + 1, j + 1, matrix, dp);

        return dp[i][j] =
            matrix[i][j] + min({down, left, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp( n, vector<int>(n, 10000000));

        int ans = 10000000;

        // Try every starting column
        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, matrix, dp));
        }

        return ans;
    }
};

															
															
