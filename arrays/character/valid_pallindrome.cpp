#include<iostream>
#include<cstring>
using namespace std;

// checking pallindrome by removing all extra symbols including space.
// should not be case sensitive

char tolowercase(char ch)     //convert to lowercase
{
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else if(ch >= '0' && ch<='9'){
        return ch;
    }
    else{
        return ch - 'A' + 'a';
    }
}

bool valchar(char ch)       // check if it contains any special character.
{
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) 
    {
        return 1;
    }
    else
    return 0;
}

bool ispallindrome(string s)   // fun for pallindrome
{
    int st = 0;
    int e = s.length() - 1;

    while(st<=e)
    {
        if(s[st] == s[e])
        {
            st++;
            e--;
            continue;
        }
        else
        {   
            return false;
        }

    }
    return true;
}

int main()
{
    string s;
    getline(cin,s); 

    string temp = "";

    for(int i = 0; i<s.length(); i++)
    {
        if(valchar(s[i]))
        {
            temp.push_back(s[i]);
        }
    }

    cout<<temp<<endl;

    for(int i = 0;i<temp.length(); i++)
    {
        temp[i] = tolowercase(temp[i]);
    }

    cout<<temp<<endl;

    if(ispallindrome(temp))
    {
        cout<<"true"<<endl;
    }

    else
    {
        cout<<"false"<<endl;
    }
}