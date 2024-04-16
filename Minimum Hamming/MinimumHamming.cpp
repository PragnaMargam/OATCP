#include <bits/stdc++.h>
using namespace std;
#define ll long long int


class Solution {
public:
    int totalHammingDistance(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int k = nums.size();
        int bits[32];
        std::fill(std::begin(bits), std::end(bits), 0);
        for (auto &n: nums) {
            int i = 0;
            while (n > 0) {
                bits[i++] += n & 0x1;
                n >>= 1;
            }
        }
        int ans = 0;
        for (const auto &n: bits) {
            ans += n * (k - n);
        }
        return ans;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    Solution sol;
    int result = sol.totalHammingDistance(nums);
    std::cout << "Total Hamming distance: " << result << std::endl;

    return 0;
}
