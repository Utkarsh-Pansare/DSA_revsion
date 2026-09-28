class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end())return 0;
        queue<string> q;
        q.push(beginWord);
        int cnt=1;

        while(!q.empty()){
            int n=q.size();

            while(n--){
                string temp=q.front();
                q.pop();

                if(temp==endWord)return cnt;
                for(int i=0 ; i<temp.size() ; i++){
                    char og=temp[i];
                    for(char c='a' ; c<='z';c++){
                        if(og==c)continue;
                        temp[i]=c;
                        if(st.find(temp)!=st.end()){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                    temp[i]=og;
                }
            }
            cnt++;
        }
        return 0;

    }
};
