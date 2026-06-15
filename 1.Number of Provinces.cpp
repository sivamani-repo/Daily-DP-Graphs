/*
    LeetCode 547. Number of Provinces
    Approach:
    - Convert adjacency matrix to adjacency list
    - Use DFS to count connected components
    - Each connected component represents one province
    Time Complexity: O(N²)
    Space Complexity: O(V + E)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for (auto neighbour : adj[node]) {
            if (!vis[neighbour]) {
                dfs(neighbour, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n, 0);

        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(i, adj, vis);
            }
        }
        return provinces;
    }
};

int main() {
    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    Solution obj;
    cout << "Number of Provinces: "
         << obj.findCircleNum(isConnected);

    return 0;
}
