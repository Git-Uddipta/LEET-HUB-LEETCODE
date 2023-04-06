//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int n, vector<int> &a) {
        // code here
         if(n==1)return 1;
        
        long long r=0;
        vector< long long> pre,suf;
        for(int i:a)r+=i,pre.push_back(r);
        r=0;
        for(int i=n-1;i>=0;i--)r+=a[i],suf.push_back(r);
        reverse(suf.begin(),suf.end());
        for(int i=1;i<n-1;i++)if(pre[i-1]==suf[i+1])return i+1;
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends