#include<string>
#include<iostream>
using namespace std;

// Remove occurences
// there will be a string named part remove the part from the string where
// it is coming  L22.

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // this solution is using in built functions but we can do it manually very easily
        // we will search the part by making window and will search in s.
        while(s.length()!=0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};