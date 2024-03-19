#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll findMaxSubarrayProduct(vector<int>array, int size) {
    ll maxProduct = INT_MIN;
    ll product = 1;

    // Traverse array from left to right
    for (int i = 0; i < size; i++) {
        product *= array[i];
        maxProduct = max(maxProduct, product);
        if (array[i] == 0) {
            product = 1;
        }
    }
 product = 1;
// Traverse array from right to left
    for (int i = size - 1; i >= 0; i--) {
        product *= array[i];
        maxProduct = max(maxProduct, product);
        if (array[i] == 0) {
            product = 1;
        }
    }

    return maxProduct;
}

int main() {
    int size;
    cin>>size;
    vector<int>numbers(size);
    for(int i=0;i<size;i++) cin>>numbers[i];
    
    if(size>0) cout << "Maximum Subarray product is " << findMaxSubarrayProduct(numbers, size)<<endl;
    else cout<<0<<endl;
    return 0;
}
