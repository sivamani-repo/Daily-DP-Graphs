/*
-------------------------------------------------------
LeetCode 994. Rotten Oranges

Approach:
- Multi-Source BFS
- Push all rotten oranges into the queue initially.
- Process level by level.
- Each BFS level represents 1 minute.
- Convert adjacent fresh oranges into rotten oranges.
- If all oranges become rotten, return minutes.
- Otherwise return -1.

Time Complexity : O(M × N)
Space Complexity: O(M × N)

-------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        if (grid.empty())
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        int totalOranges = 0;
        int rottenProcessed = 0;
        int minutes = 0;

        queue<pair<int, int>> bfsQueue;

        // Count oranges and store rotten oranges
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (grid[row][col] != 0)
                    totalOranges++;

                if (grid[row][col] == 2)
                    bfsQueue.push({row, col});
            }
        }

        int rowDir[] = {0, -1, 0, 1};
        int colDir[] = {-1, 0, 1, 0};

        while (!bfsQueue.empty()) {

            int currentLevelSize = bfsQueue.size();

            rottenProcessed += currentLevelSize;

            while (currentLevelSize--) {

                auto [currentRow, currentCol] = bfsQueue.front();
                bfsQueue.pop();

                for (int direction = 0; direction < 4; direction++) {

                    int nextRow = currentRow + rowDir[direction];
                    int nextCol = currentCol + colDir[direction];

                    if (nextRow < 0 || nextCol < 0 ||
                        nextRow >= rows || nextCol >= cols ||
                        grid[nextRow][nextCol] != 1)
                        continue;

                    grid[nextRow][nextCol] = 2;
                    bfsQueue.push({nextRow, nextCol});
                }
            }

            if (!bfsQueue.empty())
                minutes++;
        }

        return (rottenProcessed == totalOranges) ? minutes : -1;
    }
};
