#include<iostream>
using namespace std;


// string compression
// aaabbccdddd  --> a3b2c2d4   this should be the final string and we have to return its size

class solution{
private:

public:
    int compress(vector<char> &chars){
        int i = 0; 
        int ansIndex = 0;
        int n = chars.size();

        while(i<n){
            int j = i+1;
            while(j<n && chars[i] == chars[j]){
                j++;
            }
            // yaha kab aayoge?
            // ya to vector pura traverse kar diya 
            // ya fir new/different element dikh gya

            // oldchar ko store kar lo
            chars[ansIndex++] = chars[i];           // ansIndex badha do after putting the right element there this way our ansIndex will also take care of the size of the array.
            int count = j-i;                    // this will tell ki koi particular char kitni baar aaya hai.
            if(count > 1){
                // converting the count into single digit and saving in the answer
                string cnt = to_string(count);
                for(char ch : cnt){
                    chars[ansIndex++] = ch;
                }
            }
            i = j;
        }
        // we have to return the size of the final array, we were storing it in the ansIndex only.
        return ansIndex;
    }



};




