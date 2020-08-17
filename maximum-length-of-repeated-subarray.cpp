class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int m=B.size();
        int t[n+1][m+1];
        int ans=0;
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if (i==0||j==0){
                    t[i][j]=0;
                }
                else if(A[i-1]==B[j-1]){
                    // t matrix imagine kr liya kr values daal kr
                    t[i][j]=t[i-1][j-1] +1;
                    ans=max(ans,t[i][j]);
                }        
                else t[i][j]=0; //discontinuous
            }
        }
        return ans; // pehle error tha that i returned t[m][n] tc 
    }
};
