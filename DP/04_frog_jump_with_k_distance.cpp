//-->> question link :- https://takeuforward.org/practice/dsa/frog-jump-with-k-distances


// ******************* Recursive Approach *********************


class Solution {
public:
    int solve(vector<int>& heights, int index, int k) {
        if (index == 0)
            return 0;

        int minCost = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (index - j >= 0) {
                int jump = solve(heights, index - j, k)
                         + abs(heights[index] - heights[index - j]);

                minCost = min(minCost, jump);
            }
        }

        return minCost;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        return solve(heights, n - 1, k);
    }
};


//*********************** DP (Memorization) ************************

class Solution {
public:
    int solve(vector<int>& heights, int index, int k,
              vector<int>& dp) {
        if (index == 0)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int minCost = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (index - j >= 0) {
                int jump = solve(heights, index - j, k, dp)
                         + abs(heights[index] - heights[index - j]);

                minCost = min(minCost, jump);
            }
        }

        return dp[index] = minCost;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);

        return solve(heights, n - 1, k, dp);
    }
};


