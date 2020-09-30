#include<iostream>
#include<bits/stdc++.h> 
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
#define vp vector<pair<ll, ll>>
#define vs vector<string>
#define ss set<string>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define REPIT(it,a) for(auto it=a.begin();it!=a.end();it++)
#define DB(x) cout<<"Debug "<<x<<endl
#define INF (ll)10000000000
#define mod (ll)1000000007
using namespace std;

vl graph[200008];
bool visited[200008];

void addedge(ll a,ll b){
	graph[a].PB(b);
	graph[b].PB(a);
}

void bfs(ll node){
	ql q;
	q.push(node);
	visited[node]=true;
	ll curr;
	//cout<<"Here"<<endl;
	while(!q.empty()){
		curr=q.front();
		//cout<<curr<<endl;
		q.pop();
		for(auto child:graph[curr]){
			if(!visited[child]){
				cout<<curr<<" "<<child<<endl;
				q.push(child);
				visited[child]=true;
			}
		}
	}
}


int main()
{
	ll n,m,a,b,maxD=-1,maxN=0;
	cin>>n>>m;
	REP(i,0,m){
		cin>>a>>b;
		addedge(a,b);
	}
	REP(i,1,n+1){
	  if((ll)graph[i].size()>maxD){
	  	maxD=(ll)graph[i].size();
	  	maxN=i;
	  }
	}
	
	bfs(maxN);
	return 0;
}
