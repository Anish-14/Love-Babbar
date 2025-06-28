#include<iostream>
using namespace std;

// permutation in string
// L22
// we've been given two strings s1 and s2 and we have to check weather the permuation
// of the string s1 is present in the string s2 or not.


// good question
class solution{
private: 
    bool checkequal(int count1[], int count2[]){
        for(int i = 0; i<26; i++){
            if(count1[i] != count2[i]){
                return false;
            }
        }
        return true;
    }
public: 
    bool  checkInclusion(string s1, string s2){

        // character count array
        int count1[26] = {0};
        for(int i = 0; i<s1.length(); i++){
            int index = s1[i] - 'a';
            count1[index]++;
        }

        // traverse s2 string in window of size s1 and compare
        int i = 0;
        int windowsize = s1.length();
        int count2[26] = {0};

        // running for the first window, making sure that the window is not larger
        // than the string in which we are searching.
        while(i<windowsize && i<s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }       

        if(checkequal(count1,count2)){
            return 1;
        } 
        // now aage ki windows ko process karte hai
        while(i<s2.length()){
            char newchar = s2[i];
            int index = newchar - 'a';
            count2[index]++;

            char oldchar = s2[i-windowsize];
            int index = oldchar - 'a';
            count2[index]--;

            i++;

            if(checkequal(count1,count2)){
                return 1;
            }
        }

        return 0;
    }
};


