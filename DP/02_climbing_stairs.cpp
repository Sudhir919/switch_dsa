// *************** Using Recursion ******************


class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1)
            return 1;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};


// ******************** Using DP(memorization) *************************


class Solution {
public:
    int solve(vector<int>& dp, int n) {
        if (n == 0 || n == 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = solve(dp, n - 1) + solve(dp, n - 2);

        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(dp, n);
    }
};



