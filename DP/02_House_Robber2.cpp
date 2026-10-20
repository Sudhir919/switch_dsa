//******************** Using Recursion ********************

class Solution {
public:
    int solve(int i, int end, vector<int>& nums) {
        // Base case
        if (i > end) {
            return 0;
        }

        // Choice 1: Rob the current house
        int rob = nums[i] + solve(i + 2, end, nums);

        // Choice 2: Skip the current house
        int skip = solve(i + 1, end, nums);

        return max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // Special case: only one house
        if (n == 1) {
            return nums[0];
        }

        // Case 1: Exclude the last house
        int case1 = solve(0, n - 2, nums);

        // Case 2: Exclude the first house
        int case2 = solve(1, n - 1, nums);

        return max(case1, case2);
    }
};

	
	
	//*********************** Using DP (Memorization) *****************************
	
	
class Solution {
public:
    int solve(int i, int end, vector<int>& nums,
              vector<int>& dp) {
        // Base case
        if (i > end) {
            return 0;
        }

        // Return cached result
        if (dp[i] != -1) {
            return dp[i];
        }

        // Rob the current house
        int rob = nums[i] + solve(i + 2, end, nums, dp);

        // Skip the current house
        int skip = solve(i + 1, end, nums, dp);

        // Store the best result
        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        // Case 1: Exclude the last house
        vector<int> dp1(n, -1);
        int case1 = solve(0, n - 2, nums, dp1);

        // Case 2: Exclude the first house
        vector<int> dp2(n, -1);
        int case2 = solve(1, n - 1, nums, dp2);

        return max(case1, case2);
    }
};

	
