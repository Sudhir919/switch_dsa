//-->> using recursion


class Solution {
public:
    int solve(int ind, vector<int>& height) {
        // Base case
        if (ind == 0) {
            return 0;
        }

        // Jump from previous stair
        int left = solve(ind - 1, height)
                   + abs(height[ind] - height[ind - 1]);

        // Jump from two stairs back
        int right = INT_MAX;

        if (ind > 1) {
            right = solve(ind - 2, height)
                    + abs(height[ind] - height[ind - 2]);
        }

        return min(left, right);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        return solve(n - 1, height);
    }
};


// -->> Using Memorization


class Solution {
public:
    int solve(int ind, vector<int>& height, vector<int>& dp) {
        // Base case
        if (ind == 0) {
            return 0;
        }

        // If already calculated, return stored answer
        if (dp[ind] != -1) {
            return dp[ind];
        }

        // Jump from previous stair
        int left = solve(ind - 1, height, dp)
                   + abs(height[ind] - height[ind - 1]);

        // Jump from two stairs back
        int right = INT_MAX;

        if (ind > 1) {
            right = solve(ind - 2, height, dp)
                    + abs(height[ind] - height[ind - 2]);
        }

        // Store and return the minimum cost
        return dp[ind] = min(left, right);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);

        return solve(n - 1, height, dp);
    }
};



