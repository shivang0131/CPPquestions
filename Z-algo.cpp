#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define UB upper_bound
#define LB lower_bound
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define be(a) (a).begin(),(a).end()
#define deb(x) cout<< #x <<" "<<endl;
#define deb2(x, y) cout<< #x <<" "<< x <<endl<< #y <<" "<<y<<endl
#define fo(i, n) for(long long i=0; i<n; i++)
#define Fo(i, n, k) for(long long i=k; i<n; i++)
#define mod 1000000007
#define int long long

typedef long long ll;

void fileIO()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
 
typedef vector<pair<int, int>> vll;
typedef unordered_map<int, int> ump;



bool sortbysecdesc(const pair<int, int> &a, 
                    const pair<int, int> &b) 
{ 
    return a.second>b.second;
}


auto z_algo(string str)
{
    int len = str.size();

    int l = 0, r = 0;

    vector<int> z(len);

    for(int i = 1; i<len; i++)
    {
        if(i>r)
        {
            l = r = i;
            while(r<len && str[r] == str[r-l]) r++;

            z[i] = r - l;
            r--;
        }

        else
        {
            int idx = i - l;

            if(i+z[idx] <= r) z[i] = z[idx];

            else
            {
                l = i;

                while(r < len && str[r] == str[r-l]) r++;

                z[i] = r - l;
                r--;
            }
        }
    }

    return z;

}



int32_t main()
{
    IOS;
    fileIO();
    int T;
    T = 1;
    //cin>>T;

    while(T--)
    {
        string str, pat;

        cin>>str>>pat;

        string concat = pat;

        concat += '$';
        concat += str;

        auto z = z_algo(concat);

        for(int i = 0; i<z.size(); i++)
        {
            if(z[i] == pat.size()) cout<<(i - z[i] - 1)<<"\n";
        }
    }
    
    return 0;
}

