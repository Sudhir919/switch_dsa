//************************* Recursion **********************


class Solution {
public:
    int solve(int i, int j, string& s1, string& s2) {
        // Base case
        if (i == 0 || j == 0) {
            return 0;
        }

        // If characters match, extend the substring
        if (s1[i - 1] == s2[j - 1]) {
            return 1 + solve(i - 1, j - 1, s1, s2);
        }

        // Mismatch breaks the common substring
        return 0;
    }

    int longCommSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        int ans = 0;

        // Try every possible pair of ending positions
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ans = max(ans, solve(i, j, s1, s2));
            }
        }

        return ans;
    }
};


//*************************** DP( Memorization) ****************************


class Solution {
public:
    int solve(int i, int j, string& s1, string& s2,
              vector<vector<int>>& dp) {
        // Base case
        if (i == 0 || j == 0) {
            return 0;
        }

        // Return the cached result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Matching characters extend the substring
        if (s1[i - 1] == s2[j - 1]) {
            return dp[i][j] =
                1 + solve(i - 1, j - 1, s1, s2, dp);
        }

        // Mismatch breaks the substring
        return dp[i][j] = 0;
    }

    int longCommSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(
            n + 1, vector<int>(m + 1, -1)
        );

        int ans = 0;

        // Evaluate every pair of ending positions
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ans = max(ans, solve(i, j, s1, s2, dp));
            }
        }

        return ans;
    }
};
