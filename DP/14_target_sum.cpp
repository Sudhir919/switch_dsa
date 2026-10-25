
// ************** Using Recursion **************


class Solution {
public:
    int solve(int index, int sum, vector<int>& nums, int target) {
        
        // Base case: all numbers are processed
        if (index == nums.size()) {
            
             return sum == target ? 1 : 0;
        }

        // Choice 1: Add the current number
        int plus = solve(index + 1, sum + nums[index], nums, target);

        // Choice 2: Subtract the current number
        int minus = solve(index + 1, sum - nums[index], nums, target);

        // Count valid expressions from both choices
        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, 0, nums, target);
    }
};




//************* Using DP(Memorization) *****************



class Solution {
public:
    int solve(int index, int sum, vector<int>& nums, int target,
              vector<vector<int>>& dp, int total) {

        if (index == nums.size()) {
            return (sum == target) ? 1 : 0;
        }

        // Shift sum to a valid DP index
        int col = sum + total;

        if (dp[index][col] != -1) {
            return dp[index][col];
        }

        int plus = solve(index + 1, sum + nums[index],
                         nums, target, dp, total);

        int minus = solve(index + 1, sum - nums[index],
                          nums, target, dp, total);

        return dp[index][col] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;

        for (int num : nums) {
            total += num;
        }

        // Possible sums range from -total to +total
        vector<vector<int>> dp(
            nums.size(), vector<int>(2 * total + 1, -1)
        );

        if (abs(target) > total) {
            return 0;
        }

        return solve(0, 0, nums, target, dp, total);
    }
};
