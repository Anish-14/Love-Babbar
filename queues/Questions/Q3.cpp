// GFG
// First Non repeating character in a string
// search the question

// https://www.geeksforgeeks.org/problems/non-repeating-character-1587115620/1

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        int n = 26;
        vector<int> vis(n,-1);
        
        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            int index = ch - 'a';
            // first time finding the char
            if(vis[index] == -1){
                vis[index] = i;
            }
            else{
                // present multiple times
                vis[index] = -2;
            }
        }
        
        int idx = -1;
        for(int i = 0; i<n; i++){
            if(vis[i] >=0 && (idx == -1 || vis[i] < vis[idx])){
                idx = i;
            }
        }
        
        return (idx == -1) ? '$' : s[vis[idx]];
        
    }
};
