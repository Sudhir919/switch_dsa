// question link:- https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1


//************************* using recursion ******************

class Solution {
public:
    int solve(int i, int W, vector<int>& val, vector<int>& wt) {
        // Base case: only item 0 remains
        if (i == 0) {
            if (wt[0] <= W) return val[0];
            return 0;
        }

        // Don't pick the current item
        int notPick = solve(i - 1, W, val, wt);

        // Pick the current item if it fits
        int pick = 0;
        if (wt[i] <= W) {
            pick = val[i] + solve(i - 1, W - wt[i], val, wt);
        }

        return max(pick, notPick);
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        return solve(n - 1, W, val, wt);
    }
};


//********************  Using DP(Memorization)  *************************

class Solution {
public:
    int solve(int i, int W, vector<int>& val, vector<int>& wt,
              vector<vector<int>>& dp) {
        // Base case
        if (i == 0) {
            if (wt[0] <= W) return val[0];
            return 0;
        }

        // Check if already calculated
        if (dp[i][W] != -1) {
            return dp[i][W];
        }

        // Don't pick the current item
        int notPick = solve(i - 1, W, val, wt, dp);

        // Pick the current item if it fits
        int pick = 0;
        if (wt[i] <= W) {
            pick = val[i] +
                   solve(i - 1, W - wt[i], val, wt, dp);
        }

        // Store and return the maximum value
        return dp[i][W] = max(pick, notPick);
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();

        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        return solve(n - 1, W, val, wt, dp);
    }
};
