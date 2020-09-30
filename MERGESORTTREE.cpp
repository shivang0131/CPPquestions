#include<iostream>
#include<bits/stdc++.h> 
#include<limits.h>
#include<string>
#include<map>
#include<time.h>
#include<queue>
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define IN insert
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define NL cout<<endl
#define ll long long
#define ld long double
#define pl pair<ll,ll>
#define ql queue<ll>
#define vl vector<ll>
#define sl set<ll>
#define ml map<ll,ll>
#define sc set<char>
#define li list<ll>
#define vp vector<pair<ll, ll> >
#define vs vector<string>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define REPIT(it,a) for(auto it=a.begin();it!=a.end();it++)
#define DB(x) cout<<"Debug "<<x<<endl
#define N (ll)100009
#define INF (ll)10000000000
#define mod (ll)1000000007
using namespace std;
ll a[N],n,q,ch,x,y;
pl st[4*N+1];

void buildtree(ll si,ll ss,ll se)
{
 if(ss==se){
 	 if(a[ss]%2)
 	  st[si]={1,0};
 	 else
 	  st[si]={0,1};
 	 return;
 } 
 ll mid=(ss+se)/2;
 buildtree(2*si,ss,mid);
 buildtree(2*si+1,mid+1,se);
 st[si].first=st[2*si].first+st[2*si+1].first;
 st[si].second=st[2*si].second+st[2*si+1].second;
}
ll getEven(ll si,ll ss,ll se,ll qs,ll qe)
{
 if(ss>qe||se<qs)
  return 0;
 if(ss>=qs&&se<=qe)
  return st[si].second;
 ll mid=(ss+se)/2;
 ll l=getEven(2*si,ss,mid,qs,qe);
 ll r=getEven(2*si+1,mid+1,se,qs,qe);
 return (l+r);
}
ll getOdd(ll si,ll ss,ll se,ll qs,ll qe)
{
 if(ss>qe||se<qs)
  return 0;
 if(ss>=qs&&se<=qe)
  return st[si].first;
 ll mid=(ss+se)/2;
 ll l=getOdd(2*si,ss,mid,qs,qe);
 ll r=getOdd(2*si+1,mid+1,se,qs,qe);
 return (l+r);
}
void update(ll si,ll ss,ll se,ll qi,ll val)
{
 
 if(ss==se){
 	 if(a[ss]%2)
 	  st[si]={0,1};
 	 else
 	  st[si]={1,0};
 	 a[ss]=val;
 	 return;
 } 
 ll mid=(ss+se)/2;
 if(qi<=mid) 
  update(2*si,ss,mid,qi,val);
 else
  update(2*si+1,mid+1,se,qi,val);
 st[si].first=st[2*si].first+st[2*si+1].first;
 st[si].second=st[2*si].second+st[2*si+1].second;
}
int main()
{
 cin>>n;
 REP(i,1,n+1) cin>>a[i];
 buildtree(1,1,n);
 cin>>q;
 while(q--)
 {
  cin>>ch>>x>>y;
  if(ch==0){
   if(a[x]%2==y%2)
   	a[x]=y;
   else
   	update(1,1,n,x,y);
  }
  else if(ch==1)
   cout<<getEven(1,1,n,x,y)<<endl;
  else
   cout<<getOdd(1,1,n,x,y)<<endl;
 }
 return 0;
}
