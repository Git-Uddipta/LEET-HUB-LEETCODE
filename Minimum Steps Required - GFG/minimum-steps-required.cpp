//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string s) {
    // Write your code here.
    int a=0,b=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            int j=i;
            while(s[j]=='a'){
                j++;
            }
            a++;
            i=j-1;
        }
        else{
            int j=i;
            while(s[j]=='b'){
                j++;
            }
            b++;
            i=j-1;
        }
    }
    int k = min(a,b);
    return k+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends