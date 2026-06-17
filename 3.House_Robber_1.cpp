/*
-------------------------------------------------------
LeetCode 198. House Robber
-------------------------------------------------------

Problem:
You are a professional robber planning to rob houses
along a street. Adjacent houses cannot be robbed.

Return the maximum amount of money that can be robbed.

-------------------------------------------------------
Approach: Space Optimization
-------------------------------------------------------

Intuition:

At every house, we have two choices:

1. Pick the current house
   -> Add current value and move to i-2

2. Skip the current house
   -> Keep the previous answer

Transition:

pick    = nums[i] + prev2
notPick = prev1

curr = max(pick, notPick)

-------------------------------------------------------
Time Complexity:
O(N)

Space Complexity:
O(1)

-------------------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        int prev2 = nums[0];

        int prev1 = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {

            int pick = nums[i] + prev2;

            int notPick = prev1;

            int curr = max(pick, notPick);

            prev2 = prev1;

            prev1 = curr;
        }

        return prev1;
    }
};

int main() {

    vector<int> nums = {2, 7, 9, 3, 1};

    Solution obj;

    cout << "Maximum Money = "
         << obj.rob(nums);

    return 0;
}