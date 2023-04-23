//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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
class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        // Code here4
            int mn=INT_MAX;
        for(auto i: arr)
        mn=min(i,mn);
        for(auto i: arr)
        if(i%mn==1)
        return 1;
        
        return mn;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.minimumNumber(n,arr)<<endl;
    }
}
// } Driver Code Ends