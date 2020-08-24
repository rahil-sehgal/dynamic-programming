class Solution {
public:
    //note: length of Shortest commmon supersequence will be m+n-LCS(a,b)
    string shortestCommonSupersequence(string a, string b) {
            
        int m=a.size(),n=b.size();
        int t[m+1][n+1];
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
              if(i==0||j==0){ t[i][j]=0;} 
                else if(a[i-1]==b[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                    
                }
             //   else   t[i][j] = 1 + min(t[i - 1][j], t[i][j - 1]);
               else t[i][j] =max(t[i-1][j],t[i][j-1]);
            }
        }
       int i=m,j=n;
          string v; //not vector<int> v
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                v.push_back(a[i-1]);
                i--;j--;//diagonally move
            }
            else{ if(t[i-1][j]>t[i][j-1]){
                        v.push_back(a[i-1]);
                        i--;
                 }
                else  {
                    v.push_back(b[j-1]);
                    j--;
                }}
        }
        while(i>0){
            v.push_back(a[i-1]);
            i--;
        }
        while(j>0){
            v.push_back(b[j-1]);
            j--;
        }
        return v;                       
    }
    int max(int a,int b){return (a>b)?a:b;}
    
};

//"bbbaaaba"
//"bbababbb"
//ye test case hard tha --> TLE
