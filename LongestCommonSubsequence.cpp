class Solution {
public:
    int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
         int n=text2.length();

        //Recursive COde
        /* 
        if(text1[m-1]==text2[n-1]){
            
            return 1+longestCommonSubsequence( text1,text2,m-1,n-1)
            }
        else {
            return max(longestCommonSubsequence(text1,text2,m-1,n),longestCommonSubsequence(text1,text2,m,n-1));
        }
        */
        
        //Bottom up DP
              int t[m+1][n+1];
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                    if(i==0 || j==0){
                    t[i][j]=0;
                    
                }
                    else if(text1[i-1]==text2[j-1]){
            
                     t[i][j]=1+t[i-1][j-1];
                          }
                
                     else {
             t[i][j]= max(t[i][j-1],t[i-1][j]);
                     }
            }
        }
        
        return t[m][n];
    
        
    }
    
};

/*
error: control may reach end of non-void function
iska matlab function kuch return nhi kr rha
*/
