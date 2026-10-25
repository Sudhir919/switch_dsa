//************** Using Recursion ******************


class Solution {
public:
    bool solve(int i, int target, vector<int>& nums) {
        // Target achieved
        if (target == 0)
            return true;

        // No elements left
        if (i == nums.size())
            return false;

        // Skip current element
        bool skip = solve(i + 1, target, nums);

        // Take current element if possible
        bool take = false;
        if (nums[i] <= target) {
            take = solve(i + 1, target - nums[i], nums);
        }

        return take || skip;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;

        for (int x : nums)
            total += x;

        if (total % 2 != 0)
            return false;

        int target = total / 2;

        return solve(0, target, nums);
    }
};

	
//********************* DP(Memorization) ************************
	
	
class Solution {
public:
    bool solve(int i, int target, vector<int>& nums,
               vector<vector<int>>& dp) {
        if (target == 0)
            return true;

        if (i == nums.size())
            return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        // Skip current element
        bool skip = solve(i + 1, target, nums, dp);

        // Take current element
        bool take = false;
        if (nums[i] <= target) {
            take = solve(i + 1, target - nums[i], nums, dp);
        }

        return dp[i][target] = (take || skip);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for (int x : nums)
            total += x;

        if (total % 2 != 0)
            return false;

        int target = total / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(0, target, nums, dp);
    }


};
