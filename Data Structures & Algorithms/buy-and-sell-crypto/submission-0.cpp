class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int pm=INT_MAX;
      int ans=0;
      int n=prices.size();
      for(int i=0 ; i<n ; i++){
        ans=max(ans,prices[i]-pm);
        pm=min(pm,prices[i]);
      }  
      return ans;
    }
};
