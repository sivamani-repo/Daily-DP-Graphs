/*
    LeetCode 70. Climbing Stairs

    Recurrence:
    dp[i] = dp[i-1] + dp[i-2]

    Time Complexity: O(N)
    Space Complexity: O(1)
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        if (n <= 2)
            return n;

        int prev2 = 1; // ways for step 1
        int prev1 = 2; // ways for step 2

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main() {
    Solution obj;
    int n = 5;
    cout << "Ways = "
         << obj.climbStairs(n);
    return 0;
}
