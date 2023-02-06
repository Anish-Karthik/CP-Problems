#include<bits/stdc++.h>
using namespace std;
 
int sumOfDigits(int n) {
    int sum =0;
    while(n){
        sum += n%10;
        n/=10;
    }
    return sum;
}
 
void solve() {
    
    int n,q;
    cin>>n>>q;
    vector<int> arr(n,0);
    set<int> sett;
    for(int i =0; i<n; i++) {
        cin>>arr[i];
        if(arr[i]>9) sett.insert(i);
    }    int res =0;
    for(int j = 0; j<q; j++) {
        int type;
        cin>>type;
        if(type == 1) {
            int l,r;
            cin>>l>>r;
            l--;r--;
            int start = l;
            while(!sett.empty()) {
                auto it = sett.lower_bound(start);
                if(it == sett.end() || *it > r) break;
                int i = *it;
                arr[i] = sumOfDigits(arr[i]);
                if(arr[i] <= 9) {
                    sett.erase(it);
                }
                start = i + 1;
            }
        }else {
            int i;
            cin>>i;
            cout<<arr[i-1]<<endl;
        }
    }
 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}