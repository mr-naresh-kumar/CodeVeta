#include <bits/stdc++.h>
using namespace std;

// Directions for moving in the grid (right, down, left, up)
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


bool isValid(int x, int y, int n, const vector<vector<char>>& grid) {
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 'M';
}

// Function to find the minimum weighted path from 'S' to 'E'
int fMW(int n, const vector<vector<char>>& grid, pair<int, int> start, pair<int, int> end) {
    
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    
    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
       
        pair<int, int> current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        // Explore all 4 possible directions
        for (int d = 0; d < 4; d++) {
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];

            if (isValid(nx, ny, n, grid)) {
                // Calculate the cost of moving to the next cell
                int cost = (grid[x][y] == 'T' && grid[nx][ny] == 'T') ? 0 : 1;

                // Relaxation step
                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;
                    q.push({nx, ny});
                }
            }
        }
    }

    // Return the distance to the destination or -1 if unreachable
    return (dist[end.first][end.second] == INT_MAX) ? -1 : dist[end.first][end.second];
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    pair<int, int> start, end;

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') start = {i, j};
            if (grid[i][j] == 'E') end = {i, j};
        }
    }

    // Find the minimum weighted path
    int result = fMW(n, grid, start, end);
    cout << result << endl;

    return 0;
}
