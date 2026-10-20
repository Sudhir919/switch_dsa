//-->> qeustion :- https://leetcode.com/problems/house-robber/description/

//****************** Recursion *********************

class Solution {
public:

    int solve(int i, vector<int>&nums){
        
        // base case
        if(i>=nums.size()) return 0;
        
        // choice1: Rob the current house
        int rob = nums[i] + solve(i+2,nums);
        
        // choice2: Skip the current house
        int skip = solve(i+1,nums);

        return max(rob,skip);

    }

    int rob(vector<int>& nums) {
        
        return solve(0,nums);
    }
};


//******************** Using DP(Memorization ) *********************

class Solution {
public:

    int solve(int i, vector<int>&nums, vector<int>&dp){

        // base case
        if(i>=nums.size()) return 0;

        // already calculated
        if(dp[i] != -1) return dp[i];

        // rob the current house
        int rob = nums[i] + solve(i+2, nums, dp);

        // skip the current house
        int skip = solve(i+1,nums, dp);

        // store and return the answer
        return dp[i] = max(rob,skip);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n,-1);

        return solve(0,nums,dp);
    }
};
