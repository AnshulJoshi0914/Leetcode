class Solution {
public:
    int minSwaps(string s) {
        int opening=0;
        for(char ch:s){
            if(ch=='['){
                opening++;
            }
            else if(opening>0&&ch==']'){
                opening--;
            }
        }
        return (opening+1)/2;
    }
};