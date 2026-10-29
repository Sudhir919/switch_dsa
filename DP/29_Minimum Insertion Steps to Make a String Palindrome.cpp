// ******************* Recursion ****************


class Solution {
public:
    int solve(int i, int j, string& s) {
        // Empty or single-character substring
        if (i >= j) {
            return 0;
        }

        // Matching ends need no insertion
        if (s[i] == s[j]) {
            return solve(i + 1, j - 1, s);
        }

        // Insert a copy of either end
        return 1 + min(
            solve(i + 1, j, s),
            solve(i, j - 1, s)
        );
    }

    int minInsertions(string s) {
        return solve(0, (int)s.size() - 1, s);
    }
};


// ******************* DP ( Memorization ) ***********************


class Solution {
public:
    int solve(int i, int j, string& s,
              vector<vector<int>>& dp) {
        if (i >= j) {
            return 0;
        }

        // Reuse previously calculated result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Matching ends
        if (s[i] == s[j]) {
            return dp[i][j] =
                solve(i + 1, j - 1, s, dp);
        }

        // Mismatching ends
        return dp[i][j] = 1 + min(
            solve(i + 1, j, s, dp),
            solve(i, j - 1, s, dp)
        );
    }

    int minInsertions(string s) {
        int n = s.size();

        vector<vector<int>> dp(  n, vector<int>(n, -1) );

        return solve(0, n - 1, s, dp);
    }
};
