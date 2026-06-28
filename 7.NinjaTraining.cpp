# 🥷 Ninja's Training | Dynamic Programming

## 📌 Problem
Given **N** days, choose one of three tasks each day. The same task cannot be chosen on consecutive days. Find the maximum points that can be obtained.

---

## 💡 Intuition
The task chosen on the current day affects the available choices for the next day. Since the same subproblems are solved multiple times, **Dynamic Programming** is an efficient approach.

---

## 🧠 DP State

`dp[day][last]`

- `day` → Current day.
- `last` → Task performed on the previous day.
- `last = 0, 1, 2` represents the previous task.
- `last = 3` means there is no previous task restriction (used for the initial call).

---

# ✅ Memoization

```cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (dp[day][last] != -1)
        return dp[day][last];

    if (day == 0)
    {
        int maxi = 0;

        for (int task = 0; task < 3; task++)
        {
            if (task != last)
                maxi = max(maxi, points[0][task]);
        }

        return dp[day][last] = maxi;
    }

    int maxi = 0;

    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] +
                        solve(day - 1, task, points, dp);

            maxi = max(maxi, point);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n - 1, 3, points, dp);
}

int main()
{
    vector<vector<int>> points =
    {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    cout << ninjaTraining(points.size(), points);
}
```

---

# ✅ Tabulation

```cpp
#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base Case
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    dp[day][last] = max(
                        dp[day][last],
                        points[day][task] + dp[day - 1][task]
                    );
                }
            }
        }
    }

    return dp[n - 1][3];
}

int main()
{
    vector<vector<int>> points =
    {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    cout << ninjaTraining(points.size(), points);
}
```

---

# ✅ Space Optimization

```cpp
#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});

    for (int day = 1; day < n; day++)
    {
        vector<int> curr(4);

        for (int last = 0; last < 4; last++)
        {
            curr[last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    curr[last] = max(
                        curr[last],
                        points[day][task] + prev[task]
                    );
                }
            }
        }

        prev = curr;
    }

    return prev[3];
}

int main()
{
    vector<vector<int>> points =
    {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    cout << ninjaTraining(points.size(), points);
}
```

---

# ⏱ Complexity Analysis

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| Memoization | **O(N × 4 × 3)** | **O(N × 4) + O(N)** (Recursion Stack) |
| Tabulation | **O(N × 4 × 3)** | **O(N × 4)** |
| Space Optimization | **O(N × 4 × 3)** | **O(4)** |

---

# 🎯 Key Takeaways

- Converted a recursive solution into Dynamic Programming.
- Designed the DP state based on the problem constraints.
- Derived the recurrence relation from the available choices.
- Understood the difference between Memoization (top-down) and Tabulation (bottom-up).
- Optimized the space complexity by storing only the previous day's DP values.
- Learned that choosing the right DP state often makes a Dynamic Programming problem much easier to solve.
