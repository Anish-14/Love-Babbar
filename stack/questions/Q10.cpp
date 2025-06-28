#include<iostream>
#include<stack>
using namespace std;

// we have to return array containing the first smallest integer in the stack going top to bottom.
// If there is'nt a smaller number than return -1.
// save this info in an vector/array.
// eg:  if stack is [1 2 3 4] up to down , then ans should be {-1,-1,-1,-1}
// eg:  [3 4 1 2 ] up to down , then ans should be {1,1,-1,-1}.


// 2nd approach by babbar bhi dekh lena.


int number(stack<int> &s,int topElement){
    if(s.empty())                   // function to return the number .
    {
        return -1;
    }

    int top = s.top();
    s.pop();

    if(top < topElement){
        s.push(top);
        return top;
    }

    int ans = number(s,topElement);
    s.push(top);

    return ans;
}

vector<int> smallestInt(stack<int> &s){
    vector<int> a;
    
    while(!s.empty())               // func to push in the vector.
    {
        int topElement = s.top();
        s.pop();

        int numberToPush = number(s,topElement);
        a.push_back(numberToPush);
    }
    
    return a;
}



int main(){
    
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    vector<int> data;

    data = smallestInt(s);

    for(int i = 0; i<4; i++)
    {
        cout<<data[i]<<endl;
    }

}




// approach 2, good solution
// see the logic of this question whenever you want lec 57.

// eg:  if stack is [1 2 3 4] up to down , then ans should be {-1,-1,-1,-1}
// eg:  [3 4 1 2 ] up to down , then ans should be {1,1,-1,-1}.
 
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // this stack contains decreasing numbers from up to down
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}