class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        for(char it:s){
            mpp[it]++;
        }
        for(char it:t){
            mpp[it]--;
            if(mpp.find(it)==mpp.end())return false;
            if(mpp[it]==0)mpp.erase(it);
        }
        if(mpp.size()==0)return true;
        else return false;
    }
};
