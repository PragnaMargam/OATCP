#include <iostream>
#include <vector>

int countSubgrids(std::vector<std::vector<int>>& grid) {
    int size = grid.size(); // Since the number of rows and columns are equal

    std::vector<int> rowBits(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            rowBits[i] |= grid[i][j] << (size - j);
        }
    }

    int subgridCount = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int commonBits = __builtin_popcount(rowBits[i] & rowBits[j]);
            int pairsCount = commonBits * (commonBits - 1) / 2;
            subgridCount += pairsCount;
        }
    }

    return subgridCount;
}

int main() {
    int size;
    std::cout << "Enter the size of the grid (number of rows and columns): ";
    std::cin >> size;

    std::vector<std::vector<int>> grid(size, std::vector<int>(size));

    std::cout << "Enter the elements of the grid (0 or 1):" << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cin >> grid[i][j];
        }
    }

    int result = countSubgrids(grid);
    std::cout << "Number of subgrids with all ones: " << result << std::endl;

    return 0;
}
