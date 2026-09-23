class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        unordered_map<char,int> mpp;
        int maxf=0;
        int ans=0;
        while(r<n){
         mpp[s[r]]++;
         maxf=max(maxf,mpp[s[r]]);
            while((r-l+1)-maxf>k){
                mpp[s[l]]--;
                l++;
            }
           ans=max(ans,r-l+1);
           r++;
        }
        return ans;

    }
};
