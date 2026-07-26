class Solution {
public:

    int f(vector<int>& prices,int ind,int buy,vector<vector<int>>&dp){
         int n=prices.size();
         if(ind>=n) return 0;
         if(dp[ind][buy]!=-1) return dp[ind][buy];
         if(buy){
            return dp[ind][buy]=max(-prices[ind]+f(prices,ind+1,0,dp),0+f(prices,ind+1,1,dp));
         }
         else{
            return dp[ind][buy]=max(prices[ind]+f(prices,ind+2,1,dp),0+f(prices,ind+1,0,dp));
         }
    }

    int maxProfit(vector<int>& prices) {
          int n=prices.size();
          vector<vector<int>>dp(n,vector<int>(2,-1));
          return f(prices,0,1,dp);    
    }
};