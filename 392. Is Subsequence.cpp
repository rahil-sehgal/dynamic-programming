class Solution {
public:
    
    //fun fact only need to check length no need to print and check
    bool isSubsequence(string s, string t) {
        if(s.size()==LCS(s,t)){return true;}
        else return false;
    }
    int LCS(string a,string b){
        int m=a.size(),n=b.size();
        int t[m+1][n+1]; //t[m][n] par out of bounds wala error
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0){
                    t[i][j]=0;                
            }
            else if(a[i-1]==b[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
        return t[m][n];
    }
       int max(int a,int b){
        return (a>b)?a:b; }
};
