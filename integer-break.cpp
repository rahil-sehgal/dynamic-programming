class Solution {
public:
    int integerBreak(int n) {
        int dp[n+2];
        for(int i=0;i<=n+1;i++){
            dp[i]=0;
        }
        
        dp[1]=1;
        dp[2]=1;
        int a,b,c;
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<=i;j++){ //note j only goes till i
                 a=(i-j)*j; //for cases like n=6 ----> (6-3)*3 
                 b=(dp[i-j])*j; //for cases like n=8 ----->dp[8-2]*2
                 c=dp[i]; //for cases like n=1
                dp[i] =max(a,b,c);
            }
        }
        return dp[n];
    }
    int max(int a,int b,int c){
     if(a>b && a>c) {return a;}
        else if(b>a && b>c){return b;}
        else return c;
    }
};


//(i-j)j  eg: 6 ---> (6-1)*1
//for cases like 8 ----> (dp[6])*2 ----> 3*3*2 in which there are more than 2  
//----> (dp[i-j])*j
