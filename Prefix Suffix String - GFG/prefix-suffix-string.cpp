//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int prefixSuffixString(vector<string> &v,vector<string> &t){
        // Code here
        int n=v.size(),m=t.size();
        int i=0,j=0,res=0;
       for(int i=0;i<m;i++){
           string s=t[i];
           for(int j=0;j<n;j++){
               int f=v[j].find(s);
               
               if(f!=-1){
                   
                if(f==0)
               { 
                   ++res;
                    break;
                   
               }
               else {
                   string tmp=v[j].substr(f,s.size());
                   if(tmp==v[j].substr(v[j].size()- s.size()))  { 
                   ++res;
                    break;
                   
               }
               }
                   
               }
           }
       }
       return res;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends