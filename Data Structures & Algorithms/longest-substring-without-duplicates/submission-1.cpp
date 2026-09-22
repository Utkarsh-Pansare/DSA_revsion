class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int ans=0;
        int n=s.size();
        int i=0 ; 
        int j=0;
        while(i<n && j<n){
            char ch=s[j];
            mpp[ch]++;
            while(mpp[ch]>1){
                mpp[s[i]]--;
                //if(mpp[s[i]]==0)mpp.erase(s[i]);
                i++;
            }
            ans=max(j-i+1,ans);
            j++;
        }
        return ans;
    }
};
