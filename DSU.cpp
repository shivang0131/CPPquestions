#include<iostream>
#include<bits/stdc++.h> 
#include<string>
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define IN insert
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define NL cout<<endl
#define ll long long int
#define ld long double
#define vl vector<ll>
#define sl set<ll>
#define ml map<ll,ll>
#define sc set<char>
#define li list<ll>
#define vp vector<pair<ll, ll> >
#define vs vector<string>
#define ss set<string>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define REPIT(it,a) for(auto it=a.begin();it!=a.end();it++)
#define DB(x) cout<<"Debug "<<x<<endl
#define N (ll)10000
#define mod (ll)1000000007
using namespace std;
ll par[100009],R[100009];
ll find(ll a){
	if(par[a]<0)
		return a;
	return par[a]=find(par[a]);
}
void merge(ll a,ll b){
	a=find(a);
	b=find(b);
	if(a==b) return;
	if(R[a]>R[b]){
		par[b]=a;
		R[a]+=R[b];
	}
	else{
		par[a]=b;
		R[b]+=R[a];
	}
}
int main()
{
	ll n,m,a,b,q,p_a,p_b; cin>>n>>m;
    REP(i,1,n+1){
    	par[i]=-1;
    	R[i]=1;
    }
    REP(i,0,m){
    	cin>>a>>b;
    	merge(a,b);
    }
    REP(i,1,n+1){
     cout<<R[find(i)]-1<<" ";
    }
    cout<<endl;
    return 0;
}    
