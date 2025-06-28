#include<iostream>
using namespace std;

int lengthofstring(char arr[]){
    int count = 0;

    for(int i = 0 ;arr[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

void reversestring(char arr[])
{
    int s = 0 ;
    int e = lengthofstring(arr) - 1;

    while(s<e)
    {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

bool ispallindrome(char arr[])          // case sensitive
{
    int s = 0;
    int e = lengthofstring(arr) - 1;

    while(s<=e)
    {
        if(arr[s]==arr[e])
        {
            s++;
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


bool ispallindrome1(char arr[])              // not case sensitive
{
    int s = 0;
    int e = lengthofstring(arr) - 1;

    while(s<=e)
    {
        if(arr[s]==arr[e])
        {
            s++;
            e--;
            continue;
        }

        else if(int(arr[s]) == int(arr[e]) + 32)  //take care of case sensitivity. 
        {
            s++;
            e--;
            continue;
        }

        else if(int(arr[s]) == int(arr[e]) - 32)      //take care of case sensitivity. 
        {
            s++;
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
    char name[20];

    cout<<"enter your name "<<endl;
    cin>>name;
    cout<<"your name is ";
    cout<<name<<endl;

    cout<<lengthofstring(name)<<endl;
    cout<<int(name[0])<<endl;
    cout<<int(name[1])<<endl;


    cout<<"is this a pallindrome ? ";
    if(ispallindrome(name))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }


    cout<<"is this a pallindrome1 ? ";  // case sensitive one  
    if(ispallindrome1(name))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }

  

    return 0;
}