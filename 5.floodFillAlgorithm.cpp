# Flood Fill (DFS) | C++

## Problem
Given a 2D image represented by a grid of integers, each integer represents the color of a pixel.
Starting from the pixel `(sr, sc)`, change the color of that pixel and all **4-directionally connected** pixels having the **same original color** to the given new color.

## Approach
  
1. Store the original color of the starting cell.
2. If the original color is the same as the new color, return the image.
3. Perform DFS from `(sr, sc)`.
4. Recolor the current cell and recursively visit all valid 4-directional neighbors having the original color.
5. A separate `visited` array is not required because visited cells are immediately recolored.

## Complexity

- **Time:** `O(N × M)`
- **Space:** `O(N × M)` (Recursion Stack)

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int n, m;

    // Direction vectors: Up, Right, Down, Left
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(int row,
             int col,
             vector<vector<int>>& image,
             int oldColor,
             int newColor)
    {
        // Color current cell
        image[row][col] = newColor;

        // Explore all four directions
        for (int i = 0; i < 4; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];

            // Check boundary and original color
            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                image[nr][nc] == oldColor)
            {
                dfs(nr, nc, image, oldColor, newColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int color)
    {
        n = image.size();
        m = image[0].size();

        int oldColor = image[sr][sc];

        // No changes required
        if (oldColor == color)
            return image;

        dfs(sr, sc, image, oldColor, color);

        return image;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> image =
    {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    vector<vector<int>> result = obj.floodFill(image, 1, 1, 2);

    cout << "Flood Filled Image:\n";

    for (auto &row : result)
    {
        for (int cell : row)
            cout << cell << " ";

        cout << '\n';
    }

    return 0;
}
```

## Output

```text
2 2 2
2 2 0
2 0 1
```
