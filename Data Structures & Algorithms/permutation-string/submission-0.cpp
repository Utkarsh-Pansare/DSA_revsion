class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       // if(s1.size()>s2.size())return false;
      unordered_map<char,int> mpp;
      for(char ch:s1){
        mpp[ch]++;
      }  
      unordered_map<char,int> copy;
      int n=s2.size();
      int l=0;
      int r=s1.size()-1;
      while(l<n && r<n){
        bool found=true;
        copy=mpp;
        for(int i=l ; i<=r ; i++){

           if(copy.find(s2[i])==copy.end()){
            found=false;
            break;
           }   
           copy[s2[i]]--;
           if(copy[s2[i]]==0)copy.erase(s2[i]);                                                     
        }
        if(found)return true;
        l++;
        r++;
      }
      return false;
    }
};
