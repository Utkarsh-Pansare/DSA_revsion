class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n);
        vector<int> right(n);
        int lm=0;
        int rm=0;


        for(int i=0 ; i<n ; i++){
            left[i]=lm;
            lm=max(lm,height[i]);
        }
         for(int i=n-1 ; i>=0 ; i--){
            right[i]=rm;
            rm=max(rm,height[i]);
        }
        
        int ans=0;
        for(int i=0 ; i<n ; i++){
          ans+=max(0,min(left[i],right[i])-height[i]); 
        }
        return ans;
    }
};
