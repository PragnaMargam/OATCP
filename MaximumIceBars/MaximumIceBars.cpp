#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
int getMaxIceCream(vector<int>& iceCreamCosts, int availableCoins) {
        int costFrequency[100001] = {0};
        for(int i = 0; i < iceCreamCosts.size(); i++) {
            costFrequency[iceCreamCosts[i]]++;
        }

        int iceCreamCount = 0;
        for(int cost = 1; cost <= 100000; cost++) {
            if(costFrequency[cost]) {
                long long totalCost = (long long)costFrequency[cost] * cost;

                if(totalCost <= availableCoins) {
                    iceCreamCount += costFrequency[cost];
                    availableCoins -= totalCost;
                }
                else {
                    iceCreamCount += (availableCoins / cost);
                    break;
                }
            }
        }

        return iceCreamCount;
    }


int main() {
    int n;
    cin>>n;
    vector<int> iceCreamCosts(n);
    for(int i=0;i<n;i++) cin>>iceCreamCosts[i];
    int coinsAvailable;
    cin>>coinsAvailable;
    int maxIceCreams = getMaxIceCream(iceCreamCosts, coinsAvailable);
    cout<<"output:"<<maxIceCreams;
    return 0;
}
