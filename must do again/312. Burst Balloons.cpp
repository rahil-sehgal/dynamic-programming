class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n=a.size();
        if(n==0){return n;}
        int dp[n+1][n+1]; //dp[L][R]
        
        a.push_back(1);
        a.insert(a.begin(),1);
    // only valid for lists    a.push_front(1);
        
        for(int L=n-1;L>=0;L++){ //L from n-1 to 0 revrse because first last values on L needs to be computes
            for(int R=L;R<n;R++){
                for(int i=L;i<=R;i++){
                    dp[L][R]=max( dp[L][R], a[i]*a[L-1]*a[R+1] + dp[L][i-1] +dp[i+1][R]);
                    
                   
                }
            }
        }
        
        return dp[0][n-1]; //still in doubt why this dude :((
    }
};
