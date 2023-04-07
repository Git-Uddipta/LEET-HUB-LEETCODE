//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
   int addMinChar(string str)
    {    
        //code here
        int n = str.length() ;
        int start = 0 ;
        int end = n - 1 ;
        int ans = 0 ;
        while(start < end )
        {
            if(str[start] == str[end])
            {
                start++;
                end-- ;
                continue ;
            }
            ans++;       // one character added at front 
            start = 0 ;
            end = n - 1 - ans ;
        }
        return ans ;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends