//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

#define F(i, x, y) for (int i = x; i <= y; ++i)
#define Fo(i, x, y) for (int i = x; i > y; --i)
#define fo(i, n) for (int i = 0; i < n; i++)
#define eb emplace_back
#define pb push_back
#define ll long long
#define imx INT_MAX
#define imn INT_MIN
#define str string
#define ss second
#define ff first
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define sz(x) ((int)(x).size())
#define lb lower_bound
#define ub upper_bound
#define acc(x) accumulate(all(x), 0LL)
#define setbits(x) __builtin_popcountll(x)
#define l_zeros(x) __builtin_clzll(x)
#define mxEl(v) *max_element(all(v))
#define mnEl(v) *min_element(all(v))
#define t_zeros(x) __builtin_ctzll(x)
//////////////////////////////////
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;  

////////////////////////////////////
template < typename T>
    using minHeap = priority_queue<T, vector < T>, greater < T>> ;

template < typename T>
    using maxHeap = priority_queue<T> ;

////////////////////////////////////
const ll mod = 1e9 + 7;

////////////////////////////////////
 
ll modExp(ll a, ll b,ll m=mod)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
ll modInverse(ll b, ll m)
{
    ll x, y; // used in extended GCD algorithm
    ll g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;

    // m is added to handle negative x
    return (x % m + m) % m;
}

// Function to compute a/b under modulo m
ll modDivide(ll a, ll b, ll m)
{
   // a = a % m;
    ll inv = modInverse(b, m);
    
        return (inv * a) % m;
}
class DSU
{
    vector<int> rank, parent, size;

public:
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
         vvi v;
        int x=0;
        
        fo(i,n)
        {
            Job it=arr[i];
            int pro=it.profit,d=it.id,ded=it.dead;
            v.pb({pro,d,ded});
            x=max(x,ded);
        }
        
        sort(rall(v));
        
       
        vi vis(x+1);
        
        int cnt=0,pro=0;
        
        fo(i,n)
        {
            for(int j=v[i][2];j>=1;j--){
                if(!vis[j]){vis[j]=1,++cnt,pro+=v[i][0];break;}
            }
        }
        
        return {cnt,pro};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends