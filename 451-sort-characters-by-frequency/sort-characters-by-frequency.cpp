class Solution {
public:
    string frequencySort(string s) {
       int n=s.size();
       unordered_map<char,int> freq;
       int maxfreq=0;
    //    Counting Part
       for(char ch:s){
        freq[ch]++;
        maxfreq=max(maxfreq,freq[ch]);
       }

    // Sorting part 
      vector<vector<char>>bucket(maxfreq+1);
      for(auto &[c,count]:freq){
          bucket[count].push_back(c);
      }
    
    // Result
    string result="";
    result.reserve(n);

    for(int i=maxfreq;i>=0;i--){
        for(char ch:bucket[i]){
               result.append(i,ch);
        }
    }

    return result;
  }
};