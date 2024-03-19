#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int calculatePaths(int size, const vector<vector<char>>& grid) {
    vector<vector<int>> dp(size, vector<int>(size, 0));
    dp[0][0] = (grid[0][0] == '.') ? 1 : 0;

    for (int row = 1; row < size; ++row) {
        if (grid[row][0] == '.') {
            dp[row][0] = dp[row - 1][0];
        }
    }

    for (int col = 1; col < size; ++col) {
        if (grid[0][col] == '.') {
            dp[0][col] = dp[0][col - 1];
        }
    }

    for (int row = 1; row < size; ++row) {
        for (int col = 1; col < size; ++col) {
            if (grid[row][col] == '.') {
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }
    }
    return dp[size - 1][size - 1];
}

int main() {
    int gridSize;
    cout << "Enter the size of the grid: ";
    cin >> gridSize;
    vector<vector<char>> grid(gridSize, vector<char>(gridSize));
    cout << "Enter the grid ('.' for empty, '#' for blocked):" << endl;
    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            cin >> grid[row][col];
        }
    }

    cout << "Number of paths: " << calculatePaths(gridSize, grid) << endl;

    return 0;
}