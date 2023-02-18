//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class DSU
{
public:
    vector<int>   par,rank, Size; // Union by rank

    DSU(int n)
    {
        par.resize(n + 5);
        rank.resize(n + 5);
       
        Size.resize(n + 5);
        for (int i = 0; i < n + 1; i++)
            par[i] = i,Size[i]=1;
    }
    int findPar(int u)
    {
        if (par[u] == u)
            return u;
        return par[u] = findPar(par[u]);
    }
    void UnionByRank(int u, int v)
    {
         int pu = findPar(u), pv = findPar(v);
        if (rank[pu] > rank[pv])
            par[pv] = pu;
        else if (rank[pu] == rank[pv])
            par[pv] = pu, rank[pu]++;
        else
            par[pu] = pv;
    }
    void UnionBySize(int u, int v)
    {
        int su = Size[u], sv = Size[v];
        int pu = findPar(u), pv = findPar(v);
        if (su >= sv)
            par[pv] = pu, Size[pu] += Size[pv];
        else
            Size[pv] += Size[pu],par[pu]=pv;
    }
};
class Solution{
  public:
   vector<vector<string>> res;
    vector<vector<string>> accountsMerge(vector<vector<string>> &acc) {
        // code here
        int n=acc.size();
        res.resize(n);
        map<string,int> mp;
        DSU ds(n);
        
        for(int i=0;i<n;i++){
           
            for(int j=1;j<acc[i].size();j++){
                
                if(mp.find(acc[i][j])!=mp.end()){
                  
                 ds.UnionBySize(mp[acc[i][j]],i);
                    
                }
                else mp[acc[i][j]]=i;
            }
        }
        vector<vector<string>> ans;
           
        for(auto it:mp){
            int par_node=ds.findPar(it.second);
            res[par_node].push_back(it.first);
        }
         for(int i=0;i<n;i++)
         {
             if(res[i].size()==0){ continue;}
             sort(res[i].begin(),res[i].end());
             vector<string> temp;
             temp.push_back(acc[i][0]);
             for(auto it:res[i])temp.push_back(it);
             ans.push_back(temp);
         }
          sort(ans.begin(),ans.end());
        return ans;
        
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends