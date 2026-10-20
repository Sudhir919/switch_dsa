//********************** Recursive Approach ********************


int f(int day, int last, vector<vector<int>>& points) {
    if (day == 0) {
        int maxi = 0;

        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }

        return maxi;
    }

    int maxi = 0;

    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int point = points[day][task]
                      + f(day - 1, task, points);

            maxi = max(maxi, point);
        }
    }

    return maxi;
}

int ninjaTraining(int n, vector<vector<int>>& points) {
    return f(n - 1, 3, points);
}


// ******************************** using DP (Memorization) **************************


int f(int day, int last, vector<vector<int>>& points,
      vector<vector<int>>& dp) {

    if (day == 0) {
        int maxi = 0;

        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }

        return maxi;
    }

    // If already calculated, return the stored answer
    if (dp[day][last] != -1) {
        return dp[day][last];
    }

    int maxi = 0;

    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int point = points[day][task]
                      + f(day - 1, task, points, dp);

            maxi = max(maxi, point);
        }
    }

    // Store and return the answer
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));

    return f(n - 1, 3, points, dp);
}
