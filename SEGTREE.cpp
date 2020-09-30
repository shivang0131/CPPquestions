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
#define INF (ll)10000000000
#define mod (ll)1000000007
using namespace std;

void buildtree(ll a[],ll st[],ll si,ll ss,ll se)
{
 if(ss==se){
 	 st[si]=a[ss];
 	 return;
 } 
 
 ll mid=(ss+se)/2;
 buildtree(a,st,2*si,ss,mid);
 buildtree(a,st,2*si+1,mid+1,se);
 st[si]=min(st[2*si],st[2*si+1]);
}


ll query(ll a[],ll st[],ll si,ll ss,ll se,ll qs,ll qe)
{
 if(ss>qe||se<qs)
  return LLONG_MAX;
 if(ss>=qs&&se<=qe)
  return st[si];
 ll mid=(ss+se)/2;
 ll l=query(a,st,2*si,ss,mid,qs,qe);
 ll r=query(a,st,2*si+1,mid+1,se,qs,qe);
 return min(l,r);
}
int main()
{

 ll n;
 cin>>n;
 ll a[n],st[2*n+1],q,qs,qe;
 REP(i,0,n) cin>>a[i];
 buildtree(a,st,1,0,n-1);
 cin>>q;
 while(q--)
 {
  cin>>qs>>qe;
  cout<<query(a,st,1,0,n-1,qs,qe)<<endl;
 }
 return 0;
}
