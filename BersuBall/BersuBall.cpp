#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int n;
    cin>>n;
    bool arr[n+1]={0};
    int a[n];
    bool checker=false;
    int mex=0;
    int idx=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        arr[a[i]]= true;
        if(a[i]==mex){
            int x=mex;
            while(checker!=true){
                if(!arr[x]){
                    mex=x;
                    checker= true;
                }
                x++;
            }
            checker=false;
            idx=i;
        }
    }
    if(mex==0){
        cout<<2<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<2<<" "<<n<<endl;
        return;
    }
    int m=0;
    bool arr2[n+1]={0};
    for(int i=idx+1; i<n; i++){
        arr2[a[i]]=true;
        if(a[i]==m){
            int x=m;
            while(checker!=true){
                if(!arr2[x]){
                    m=x;
                    checker= true;
                }
                x++;
            }
            checker=false;
        }
    }
    
    if(m==mex){
        cout<<2<<endl;
        cout<<1<<" "<<idx+1<<endl;
        cout<<idx+2<<" "<<n<<endl;
        return;
    }
    cout<<-1<<endl;

}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}