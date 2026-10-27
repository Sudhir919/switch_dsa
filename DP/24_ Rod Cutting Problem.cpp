// *************** Using Recursion ********************


class Solution {
public:
    int solve(int i, vector<int>& price, int length) {
        
        // Only pieces of length 1 are available
        if (i == 0) {

            return length * price[0];
        }

        // Choice 1: Do not take the current piece
        int notTake = solve(i - 1, price, length);

        // Choice 2: Take the current piece
        int take = 0;
        int pieceLength = i + 1;

        if (pieceLength <= length) {
            take = price[i] + solve(i, price, length - pieceLength);
        }

        return max(take, notTake);
    }

    int cutRod(vector<int>& price) {

        int n = price.size();
        return solve(n - 1, price, n);

    }
};



//************************* DP (Memorization) ***************************8


class Solution {
public:
    int solve(int i, vector<int>& price, int length, vector<vector<int>>& dp) {

        // Base case
        if (i == 0) {
            return length * price[0];
        }

        // Return the cached result
        if (dp[i][length] != -1) {
            return dp[i][length];
        }

        // Choice 1: Do not take the current piece
        int notTake = solve(i - 1, price, length, dp);

        // Choice 2: Take the current piece
        int take = 0;
        int pieceLength = i + 1;

        if (pieceLength <= length) {
            take = price[i] + solve(i, price, length - pieceLength, dp);
        }

        // Cache and return the maximum value
        return dp[i][length] = max(take, notTake);
    }

    int cutRod(vector<int>& price) {
        int n = price.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(n - 1, price, n, dp);
    }
};
