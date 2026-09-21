class Solution {
public:
    int maxArea(vector<int>& heights) {
        int wat=0;
        int i=0;
        int j=heights.size()-1;

        while(i<j){
            wat=max(wat,(j-i)*min(heights[i],heights[j]));
            if(heights[i]<heights[j])i++;
            else j--;
        }
        return wat;
    }
};
