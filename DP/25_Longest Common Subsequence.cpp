/*

Rules to write

I) express in index
ii) explore possibility in index
iii) take the best among them

*/


//**************** Recursion *******************


class Solution {
public:
    int solve(int i, int j, string& text1, string& text2) {
        
        // Base case: one string has no characters left
        if (i < 0 || j < 0) {
            return 0;
        }

        // Case 1: Characters match
        if (text1[i] == text2[j]) {
            return 1 + solve(i - 1, j - 1, text1, text2);
        }

        // Case 2: Characters do not match
        int skipFirst = solve(i - 1, j, text1, text2);
        int skipSecond = solve(i, j - 1, text1, text2);

        return max(skipFirst, skipSecond);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        return solve(n - 1, m - 1, text1, text2);
    }
};



//**************** DP (Memorization) ******************


class Solution {
public:
    int solve(int i, int j, string& text1, string& text2,
              vector<vector<int>>& dp) {

        // Base case
        if (i < 0 || j < 0) {
            return 0;
        }

        // Return the cached result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Case 1: Characters match
        if (text1[i] == text2[j]) {
            return dp[i][j] =
                1 + solve(i - 1, j - 1, text1, text2, dp);
        }

        // Case 2: Characters do not match
        int skipFirst = solve(i - 1, j, text1, text2, dp);
        int skipSecond = solve(i, j - 1, text1, text2, dp);

        return dp[i][j] = max(skipFirst, skipSecond);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, text1, text2, dp);
    }
};
