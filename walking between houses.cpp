#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long
#define endl "\n"

int solve() {
	int n, k, s;
	cin >> n >> k >> s;

	if( !(k <= s && s <= (n-1) * k) ) {
		cout << "NO";
		return 0;
	}
	cout<<"YES"<<endl;
	int minp = k;
	int pos = 1;
	int remaining = s - minp;
	for(int i = 0; i< k; i++) {
		int diff = 1;
		minp = min(remaining,n-2);
		diff += minp;
		remaining -= minp;

		if(i%2 == 0 ) {
			pos+= diff;
		} else {
			pos-= diff;
		}
		cout << pos << " ";
	}
	return 0;
}

#undef int
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t = 1;
	// cin>>t;
	while(t--){
		solve();
	    cout<<endl;
	}   

    return 0;
}
