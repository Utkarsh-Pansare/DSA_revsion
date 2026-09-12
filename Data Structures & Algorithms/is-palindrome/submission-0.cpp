class Solution {
public:
    bool isPalindrome(string t) {
       int i=0;
       string s="";
       for(char c:t){
        if(isalnum(c)){
        s+=tolower(c);
        }
       }
       int j=s.size()-1;
       
       while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
       } 

       return true;
    
    }

};
