#include<iostream>
#include<stack>
using namespace std;


// find faaltu brackets in the string given.
// eg  ((a+b)) yaha 1 pair of bracket is useless 
// So if you find a useless bracket then return "true".

void printStack(stack<char> a){           
    if(a.empty()){                  // function for printing the stack.
        return;
    }
    cout<<a.top()<<endl;
    a.pop();
    printStack(a);
}

bool uselessBracket(string s)
{
    stack<char> st;
    for(int i = 0; i<s.length(); i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }

        else
        {
            if(ch == ')')
            {
                bool isReductantBracket = true;

                while(st.top() != '(')
                {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isReductantBracket = false;
                    }
                    st.pop();
                }

                if(isReductantBracket){
                    return true;
                }
            }
        }
    }
    return false; 
}

int main(){
    // stack<char> a;
    // a.push('a');
    // a.push('v');
    // a.push('l');
    // a.push('f');

    // printStack(a);
    // cout<<endl;
    // // uselessBracket(a);
    // cout<<endl;
    // printStack(a);

    string formula = "((a+b))";
    bool answer = uselessBracket(formula);
    cout<<answer<<endl;

    string anish = "((a+b)+c)";
    bool ans = uselessBracket(anish);
    cout<<ans<<endl;

}