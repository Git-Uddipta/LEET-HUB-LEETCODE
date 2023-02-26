
#define F(i, x, y) for (int i = x; i <= y; ++i)
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
#define sz(x)((int)(x).size())
#define lb lower_bound
#define ub upper_bound
#define acc(x) accumulate(all(x), 0 LL)
#define setbits(x) __builtin_popcountll(x)
#define l_zeros(x) __builtin_clzll(x)
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
/////////////////////////////////
class Solution
{
    public:
        vector<int> divisibilityArray(string word, int m)
        {
            int n = sz(word);
            vi ans;
            ll d = 0;
            int i = 0;
            fo(i, n)
            {
                d = d *10 + (word[i] - '0');
                if (d % m == 0) ans.pb(1);
                else ans.pb(0);
                d %= m;
            }
            
            return ans;
        }
};