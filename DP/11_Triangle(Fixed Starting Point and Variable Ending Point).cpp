/*

==>> Approach

i. represent in (i,j) form  -->> base case
ii. explore all path
iii. minm of all paths


  */

//********************** Recursion *******************


class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Base case: last row
        if (i == n - 1) {
            return triangle[i][j];
        }

        // Move down
        int down = triangle[i][j] + solve(i + 1, j, triangle);

        // Move diagonally down-right
        int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle);

        return min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(0, 0, triangle);
    }
};

	
	//********************** Using DP( Memorization) ************************
	
	
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {
        int n = triangle.size();

        // Base case: last row
        if (i == n - 1) {
            return triangle[i][j];
        }

        // Already calculated
        if (dp[i][j] != 1000000000) {
            return dp[i][j];
        }

        // Move down
        int down = triangle[i][j]
                 + solve(i + 1, j, triangle, dp);

        // Move diagonally down-right
        int diagonal = triangle[i][j]
                     + solve(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(
            n, vector<int>(n, 1000000000)
        );

        return solve(0, 0, triangle, dp);
    }
};

	
