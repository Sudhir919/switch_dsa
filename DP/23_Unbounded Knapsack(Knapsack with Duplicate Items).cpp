
//******************* Using Recursion ************************

class Solution {
public:
    int solve(int i, vector<int>& val, vector<int>& wt,int capacity) {

        // Base case: only item 0 is available
        if (i == 0) {
            return (capacity / wt[0]) * val[0];
        }

        // Choice 1: Do not take the current item
        int notTake = solve(i - 1, val, wt, capacity);

        // Choice 2: Take the current item
        int take = 0;

        if (wt[i] <= capacity) {
            take = val[i] +  solve(i, val, wt, capacity - wt[i]);
        }

        return max(take, notTake);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = val.size();
        return solve(n - 1, val, wt, capacity);
        
    }
};



//************************** Using Dp(Memorization) *********************************


class Solution {
public:
    int solve(int i, vector<int>& val, vector<int>& wt, int capacity, vector<vector<int>>& dp) {

        // Base case
        if (i == 0) {
            return (capacity / wt[0]) * val[0];
        }

        // Return the previously calculated answer
        if (dp[i][capacity] != -1) {
            return dp[i][capacity];
        }

        // Choice 1: Do not take the current item
        int notTake = solve(i - 1, val, wt, capacity, dp);

        // Choice 2: Take the current item
        int take = 0;

        if (wt[i] <= capacity) {
            take = val[i] + solve(i, val, wt, capacity - wt[i], dp);
        }

        // Store and return the best answer
        return dp[i][capacity] = max(take, notTake);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {

        int n = val.size();

        vector<vector<int>> dp( n, vector<int>(capacity + 1, -1));

        return solve(n - 1, val, wt, capacity, dp);

    }
};
