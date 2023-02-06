#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
 
int solve(){
 
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i =0; i<n; i++) cin>>arr[i];
    
    sort(arr.begin(),arr.end());
 
    long long spell1 = 0;
    int current_highest = 1;
 
    for(int i = 0; i<n ; i++) {
        if(arr[i] >= current_highest) {
            spell1 += arr[i] - current_highest;
            current_highest++;
        }
    }
 
    cout<<spell1<<endl;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();        
        }
    return 0;
}
