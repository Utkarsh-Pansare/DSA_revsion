class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //sort(strs.begin(),strs.end())
        // int n=strs.size();
        // vector<pair<string,int>> v;
        // for(int i=0 ; i<n ; i++){
        //     v.push_back({strs[i],i});
        // }
        // sort(v.begin(),v.end());
        
        // int n=strs.size();
        // vector<vector<string>> ans;
        // vector<int> vis(n,0);
        // for(int i=0 ; i<n ; i++){
        //     if(vis[i])continue;
        //     vector<int> v(26,0);
        //    int a= strs[i].size();
        //    string q=strs[i];
        //    for(char ch:q){
        //     v[ch-'a']++;
        //    }
        //     for(int j=0 ; j<n ; j++){

        //     }
        // }

        unordered_map<string,vector<string>> mpp;
        for(string s:strs){
            string key=s;
            sort(key.begin(),key.end());
            mpp[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto &it:mpp){
            ans.push_back(it.second);
        }
        return ans;

    }
};
