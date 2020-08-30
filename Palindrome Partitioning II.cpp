class Solution {
public:
    int static t[2001][2001];
    
    int minCut(string s) {
        memset(t,-1,size(t));
       return solve(s,0,s.size()-1);
    }
    int solve(string s,int i,int j){
        
        //Base Condn
        if(i>=j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        else if(isPallindrome(s,i,j)){return 0;}
        int mn=INT_MAX;
        
        for(int k=i;k<=j-1;k++){
            int temp=solve(s,i,k)+solve(s,k+1,j)+1;
            if(temp<mn){
                mn=temp;
            }
        }
        
        return t[i][j]=mn;
    }
    bool isPallindrome(string s,int i,int j){
        int flag=1;
        if(i>=j){return true;}
        
        while(i<j){
            if(s[i]!=s[j]){flag=0;}
            i++;j--;
        }
        if(flag==0){return false;} else return true;
    }
};
