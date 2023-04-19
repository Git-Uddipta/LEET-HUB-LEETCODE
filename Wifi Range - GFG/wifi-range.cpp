//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        // code here
        vector<int> diff(n+2);
        
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                int l=max(0,i-x+1),r=min(n,i+x+1);
                diff[l]++,
                diff[r+1]--;
            }
        }
         for(int i=1;i<=n;i++){
           
             diff[i]+=diff[i-1];
             if(!diff[i]){return 0;}
         }
         return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends