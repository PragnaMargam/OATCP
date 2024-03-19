#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int count(int n) {
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=6;i++) {
        for(int j=i;j<=n;j++) dp[j]+=dp[j-i];
    }
    return dp[n];
}
int main() {
    ll n;
    cin>>n;
    while(n--) {
        ll sum;
        cin>>sum;
        if(sum<0) cout<<"Not Possible"<<endl;
        else{
             cout<<count(sum)<<endl;
        }   
    }
    return 0;
}