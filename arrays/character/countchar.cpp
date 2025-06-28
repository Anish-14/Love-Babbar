#include<iostream>
#include<cstring>
using namespace std;

//tell how many an alphabet came in a letter.

int main()
{
    string name;
    getline(cin,name);

    int ascii[26] = {0};  // stores all alphabets.
    
    for(int i = 0 ; i<name.length(); i++)
    {
        int temp = name[i] -'a';                // counts alphabets
        ascii[temp]++;
    }

    for(int i = 0; i<26; i++)                   // prints all alphabets which are coming that particular word and count it
    {
        if(ascii[i] != 0)
        {
            cout<<char( i + 'a')<<" "<<ascii[i]<<endl;
        }
    }
    
}