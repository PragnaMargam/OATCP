#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int calculateMaxRotateFunction(vector<int>& nums, int size) {
        if (nums.empty() || size == 0)
            return 0;
        int totalSum = 0, currentSum = 0, maximum = INT_MIN;
        for (int i = 0; i < size; i++) {
            totalSum += nums[i];
            currentSum += i * nums[i];
        }
        vector<int> dp(size);
        dp[0] = currentSum;
        maximum = dp[0];
        for (int i = 1; i < size; i++) {
            dp[i] = dp[i - 1] + totalSum - size * nums[size - i];
            maximum = max(maximum, dp[i]);
        }
        return maximum;
    }

int main() {
    int size;
    cin>>size;
    vector<int> nums(size);
    for(int i=0;i<size;i++) cin>>nums[i];
    if(size>0) cout << calculateMaxRotateFunction(nums, size) << endl;
    else cout<<"empty array";
    return 0;
}
