#include             <bits/stdc++.h>
#include             <ext/pb_ds/assoc_container.hpp>
#include             <ext/pb_ds/tree_policy.hpp>
#define PRE(x,p)     cout<<setprecision(x)<<p; 
#define pb           push_back
#define mp           make_pair
#define f            first
#define s            second
#define pi           3.14159265358979
#define mod          (ll)(1e9 + 7)
#define endl         "\n"
#define high         1e18
#define low          -1e18
#define ll           long long int
#define ld           long double
#define mem(x,val)   memset(x,0,sizeof(x));
#define rep(i,l,r)   for(ll i=l;i<=r;i++)
#define p(a)         for(auto i:a) cout<<i<<' '; cout<<endl;
#define vll          vector<ll> 
#define vb           vector<bool>
#define vpll         vector<pair<ll,ll>>
#define vi           vector<int>
#define vpi          vector<pair<int, int>>
#define vvll         vector<vector<ll>>
#define vvi          vector<vector<int>>
#define vvvll        vector<vector<vector<ll>>>
#define pll          pair<ll,ll>
#define vs           vector<string>
#define vvpll        vector<vector<pair<ll, ll>>>
#define vvpi         vector<vector<pair<int, int>>>
#define vpii         vector<pair<int, int>>
#define sz(a)        (ll)a.size()
#define po(x)        (ll)(1ll<<x)
#define all(x)       begin(x), end(x)
#define speed        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define yes          {cout<<"YES"<<endl;return;}
#define no           {cout<<"NO"<<endl; return;}
#define ok           cout<<"ok"<<endl;
#define ordered_set  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


using namespace std;
using namespace __gnu_pbds;

void showa(ll a[],ll n)  { for(ll i=1;i<=n;i++) cout<<a[i]<<' ';  cout<<endl;  }
ll ison(ll w ,ll i)    {return  w&(1ll<<i);}
void amax(ll &a, ll b){ a=max(a,b); }
void amin(ll &a, ll b){ a=min(a,b);}
void modadd(ll &a , ll b) {a=((a%mod)+(b%mod))%mod;}
void modsub(ll &a , ll b) {a=((a%mod)-(b%mod)+mod)%mod;}
void modmul(ll &a , ll b) {a=((a%mod)*(b%mod))%mod;}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)     {cerr << t<<' ';}
void _print(int t)    {cerr << t<<' ';}
void _print(string t) {cerr << t<<' ';}
void _print(char t)   {cerr << t<<' ';}
void _print(ld t)     {cerr << t<<' ';}
void _print(double t) {cerr << t<<' ';}
template<class T,class V> void _print(pair <T, V> p);
template<class T>void _print(vector <T> v);
template<class T>void _print(vector <T> v);
template<class T>void _print(set <T> v);
template<class T,class V> void _print(map <T, V> v);
template<class T>void _print(multiset <T> v);
template<class T,class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template<class T>void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T>void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T>void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T,class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//const ll l=30;   //log2(n)
//const ll N=200005;

ll n,m,sum_k;

ll get(ll x)
{
   x%=mod;
   ll ans=(x*(x+1))%mod;
   modmul(ans,500000004);
   return ans;
}
ll getrow(ll x)  //get value of xth row
{
  ll ans= get(x*m);
  modsub( ans, get ((x-1)*m));
  return ans;
}
ll getcol(ll x)  //get value of xth row
{
  ll ans=n;
  ll here=(2*x)%mod;
  modadd(here, (n-1)*m);
  modmul(ans,here);
  modmul(ans,500000004);
  return ans;
}
void check(ll x , ll l , ll r){
  assert(x>=l && x<=r);
}

ll rec(vvll vec)
{
   ll ans=0;
   for(vll v:vec)
   {
     ll here=1;
     for(ll x:v) modmul(here,x); 
     modadd(ans,here);
   }
   return ans; 
}
void solve()
{
  ll k;
  assert(cin>>n>>m>>k);
  sum_k+=k;
  check(n,1,1e9);
  check(m,1,1e9);
  check(k,1,2e5);
  check(sum_k,1,2e5);
  map<ll,ll>row,col;
  rep(i,1,k)
  {
    ll type,x,c;
    assert(cin>>type>>x>>c);
    check(type,0,1);
    check(c,0,1e9);
    if(type==0)
    {
      check(x,1,n);
      assert(row.count(x)==0);
      row[x]=c;
    }
    if(type==1)
    {
      check(x,1,m);
      assert(col.count(x)==0);
      col[x]=c;
    }
  }
  ll yy=0;
  ll cc_yy=0;

  for(auto it:col) 
  {
    modadd(yy,it.s);
    modadd(cc_yy, it.f*it.s);
  }

  ll ans=get(n*m);
  for(auto it:row) modadd(ans,getrow(it.f) * (it.s-1+mod)%mod);
  for(auto it:col) modadd(ans,getcol(it.f) * (it.s-1+mod)%mod);
  
  ll tot_c=col.size()%mod;
  ll col_sum=0;
  for(auto it:col) modadd(col_sum,it.f);
  for(auto it:row)
  {
    ll r=it.f;
    ll x=it.s;

    ll here= ((r-1)*m)%mod ;
    modmul(here,x);
    modmul(here,yy);

    ll toadd=x;
    modmul(toadd, cc_yy);
    modadd(here,toadd);
    modadd(ans,here);
    
    ll tosub1=rec({{m,r-1,x,tot_c},{x,col_sum}});
    ll tosub2=rec({{m,r-1,yy},{cc_yy}});
    modsub(tosub2, m*((r-1)*tot_c)%mod);
    modsub(tosub2, col_sum);
    
    modsub(ans,tosub1);
    modsub(ans,tosub2);

  }   
  cout<<ans<<endl;

}
 
signed main()
{
   #ifndef ONLINE_JUDGE
    freopen("input_5.in", "r", stdin);
    freopen("output_5.out", "w", stdout);
    #endif 
  speed

  ll t=1;  
  assert(cin>>t);
  check(t,1,100);
  
  for(ll test=1;test<=t;test++)
  {
    solve();
  }
  return 0;
}      
