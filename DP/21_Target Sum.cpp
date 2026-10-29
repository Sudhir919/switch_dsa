
//************************* Using Recursion ****************************


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



//************************ Using DP (Memorization) *********************************8


class Solution {
public:
    int solve(int index, int sum, vector<int>& nums, int target,
              vector<vector<int>>& dp, int offset) {

        // Base case: all numbers are processed
        if (index == nums.size()) {
            return sum == target ? 1 : 0;
        }

        // Convert negative or positive sum to a valid DP index
        int col = sum + offset;

        // Return cached result
        if (dp[index][col] != -1) {
            return dp[index][col];
        }

        // Choice 1: Add current number
        int plus = solve(index + 1, sum + nums[index],
                         nums, target, dp, offset);

        // Choice 2: Subtract current number
        int minus = solve(index + 1, sum - nums[index],
                          nums, target, dp, offset);

        return dp[index][col] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;

        for (int num : nums) {
            total += num;
        }

        // Target is unreachable if its absolute value exceeds total
        if (abs(target) > total) {
            return 0;
        }

        int offset = total;

        // Possible sums range from -total to +total
        vector<vector<int>> dp(
            n, vector<int>(2 * total + 1, -1)
        );

        return solve(0, 0, nums, target, dp, offset);
    }
};
