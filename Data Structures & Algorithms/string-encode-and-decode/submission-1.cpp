class Solution {
public:
   string a="utkarsh";
    string encode(vector<string>& strs) {
        string s="";
        
        for(auto it:strs){
            s+=it;
            s+=a;
        }
         return s;
    }

    vector<string> decode(string s) {
        int n=s.size();
        vector<string> og;
        int i=0;
        int j=0;

        while(i<=j && i<n && j<n-1){
            string k=s.substr(j,7);
            if(k=="utkarsh"){
                string temp=s.substr(i,j-i);
                og.push_back(temp);
                i=j+7;
                j+=7;
            }
            else{
                j++;
            }
        }
        return og;
    }
};
