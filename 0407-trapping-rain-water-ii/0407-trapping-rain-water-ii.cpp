class Solution {
private:
    // Function to check if the given cell (i, j) is within bounds
    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // Get the number of rows (m) and columns (n)
        int m = heightMap.size();
        int n = heightMap[0].size();

        // Create a 2D visited array initialized to false
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Priority queue (min-heap) to always process the cell with the minimum height
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        // Add all the boundary cells to the priority queue and mark them as visited
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Boundary cells (first row, last row, first column, last column)
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        // Directions array for moving up, down, left, and right
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int water = 0;  // To keep track of the total trapped water

        // Process cells in the priority queue
        while (!pq.empty()) {
            auto p = pq.top();  // Get the cell with the smallest height
            pq.pop();

            int height = p.first;  // Height of the current cell
            int row = p.second.first;  // Row of the current cell
            int col = p.second.second;  // Column of the current cell

            // Check all four possible directions
            for (auto& dir : directions) {
                int nextRow = row + dir[0];
                int nextCol = col + dir[1];

                // If the neighboring cell is within bounds and not visited
                if (isSafe(nextRow, nextCol, m, n) && visited[nextRow][nextCol] == false) {
                    // Calculate water trapped at this neighboring cell
                    water += max(0, height - heightMap[nextRow][nextCol]);

                    // Push the next cell with the max of its own height or the current height
                    pq.push({max(height, heightMap[nextRow][nextCol]), {nextRow, nextCol}});

                    // Mark the neighboring cell as visited
                    visited[nextRow][nextCol] = true;
                }
            }
        }

        // Return the total trapped water
        return water;
    }
};