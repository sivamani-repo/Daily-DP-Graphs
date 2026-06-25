# Frog Jump | Space Optimization | C++

## Problem

A frog wants to reach the last step with minimum energy. It can jump either **1 step** or **2 steps** at a time.

The energy required for a jump from step `i` to `j` is:

```text
abs(heights[i] - heights[j])
```

Return the minimum energy required to reach the last step.

## Approach

- Let `dp[i]` represent the minimum energy required to reach the `iᵗʰ` step.
- For every step, check two possible jumps:
  - **One Step Jump:** From `i-1`
  - **Two Step Jump:** From `i-2`
- Store the minimum of both.
- Since `dp[i]` depends only on `dp[i-1]` and `dp[i-2]`, we replace the DP array with two variables to achieve **O(1)** space.

## Complexity

- **Time:** `O(N)`
- **Space:** `O(1)`

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int frogJump(vector<int>& heights)
{
    int n = heights.size();

    // Previous Two States
    int prev = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        // One Step Jump
        int left = prev + abs(heights[i] - heights[i - 1]);

        // Two Step Jump
        int right = INT_MAX;

        if (i > 1)
        {
            right = prev2 + abs(heights[i] - heights[i - 2]);
        }

        // Current Minimum Energy
        int curr = min(left, right);

        // Update Previous States
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> heights = {30, 10, 60, 10, 60, 50};

    cout << frogJump(heights);

    return 0;
}
```

## Output
```text
40
```
