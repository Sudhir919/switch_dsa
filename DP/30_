// *********************** Recursion **************************


class Solution {
public:
    int solve(int i, int j, string& s1, string& s2) {
        // If either prefix is empty
        if (i == 0 || j == 0) {
            return 0;
        }

        // Characters match
        if (s1[i - 1] == s2[j - 1]) {
            return 1 + solve(i - 1, j - 1, s1, s2);
        }

        // Characters differ: skip one character
        return max(
            solve(i - 1, j, s1, s2),
            solve(i, j - 1, s1, s2)
        );
    }

    int minOperations(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        int lcs = solve(n, m, s1, s2);

        return (n - lcs) + (m - lcs);
    }
};


// ************************** DP ( Memorization ) ************************


class Solution {
public:
    int solve(int i, int j, string& s1, string& s2,
              vector<vector<int>>& dp) {
        if (i == 0 || j == 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s1[i - 1] == s2[j - 1]) {
            return dp[i][j] =
                1 + solve(i - 1, j - 1, s1, s2, dp);
        }

        return dp[i][j] = max(
            solve(i - 1, j, s1, s2, dp),
            solve(i, j - 1, s1, s2, dp)
        );
    }

    int minOperations(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(
            n + 1, vector<int>(m + 1, -1)
        );

        int lcs = solve(n, m, s1, s2, dp);

        int deletions = n - lcs;
        int insertions = m - lcs;

        return deletions + insertions;
    }
};
