//******************* Recursion *****************


class Solution {
public:
    int solve(int i, int j, string& s) {
        // Empty range
        if (i > j) {
            return 0;
        }

        // Single character is a palindrome
        if (i == j) {
            return 1;
        }

        // Both ends match
        if (s[i] == s[j]) {
            return 2 + solve(i + 1, j - 1, s);
        }

        // Skip either the left or right character
        return max(
            solve(i + 1, j, s),
            solve(i, j - 1, s)
        );
    }

    int longestPalindromeSubseq(string s) {
        return solve(0, (int)s.size() - 1, s);
    }
};

//*********************** DP( Memorization) *****************


class Solution {
public:
    int solve(int i, int j, string& s,
              vector<vector<int>>& dp) {
        // Empty range
        if (i > j) {
            return 0;
        }

        // Single character
        if (i == j) {
            return 1;
        }

        // Return cached result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Matching characters
        if (s[i] == s[j]) {
            return dp[i][j] =
                2 + solve(i + 1, j - 1, s, dp);
        }

        // Mismatching characters
        return dp[i][j] = max(
            solve(i + 1, j, s, dp),
            solve(i, j - 1, s, dp)
        );
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1) );

        return solve(0, n - 1, s, dp);
    }
};
