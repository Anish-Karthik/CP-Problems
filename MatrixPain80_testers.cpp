#include <bits/stdc++.h>
using namespace std;
typedef double db; 
typedef long long ll;
typedef unsigned long long ull;
const int N=1000010;
const int LOGN=28;
const ll  TMD=1000000007;
const ll  INF=2147483647;
ll  T,n,m,k;
ll  S1,S2,ans;
ll  q[N],x[N],v[N];

//-------------------------------------------------
//????:fac[],inv[],TMD,N(??)
//??:TMD?? 

ll pw(ll x,ll p)
{
	if(!p) return 1;
	ll y=pw(x,p>>1);
	y=(y*y)%TMD;
	if(p&1) y=(y*(x%TMD))%TMD;	//???:???????????! 
	return y;
}

ll inv(ll x)
{
	return pw(x,TMD-2);
}

//-------------------------------------------------

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		for(int i=1;i<=k;i++) scanf("%lld%lld%lld",&q[i],&x[i],&v[i]);
		S1=(ll)m*(m+1)/2%TMD;S2=m;
		for(int i=1;i<=k;i++) if(q[i]) S1=(S1+(ll)x[i]*(v[i]-1+TMD))%TMD,S2=(S2+(v[i]-1+TMD))%TMD;
		ans=(S1+S1+(ll)m*(n-1)%TMD*S2%TMD)*n%TMD*inv(2)%TMD;
		for(int i=1;i<=k;i++) if(!q[i]) ans=(ans+(ll)(v[i]-1+TMD)*(S1+(ll)m*(x[i]-1)%TMD*S2%TMD))%TMD;
		printf("%lld\n",ans);
	}
	
	return 0;
}
