class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      int k = p.size();
int start = 0;
int end = k - 1;
if (p.size() > s.size()) return {};
        vector<int>freq(26,0);
        vector<int>wfreq(26,0);
        vector<int>ans;
        for(auto a:p){
            freq[a-'a']++;
        }
                  for (int i = 0; i < k; i++) {
    wfreq[s[i] - 'a']++;
}
       while (end < s.size()) {
    if (freq == wfreq) {
        ans.push_back(start);
    }

   wfreq[s[start] - 'a']--;

   start++;
   end++;

   
    if(end<s.size()){
          wfreq[s[end] - 'a']++;
    }
}
  
           

            
            
        
        return ans;
    }
};