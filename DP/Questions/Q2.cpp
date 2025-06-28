#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<unordered_map> 
#include<list>
using namespace std;

float p(int a, int b){
    if(a == 4){
        return 1;
    }
    if(b == 4){
        return 0;
    }

    cout<<0.5*p(a+1,b) + 0.5*p(a,b+1)<<endl;;
    float ans = 0.5*p(a+1,b) + 0.5*p(a,b+1);
    return ans;

}

int main(){
    int a = 1;
    int b = 0;

    float ans = p(a,b);
    cout<<ans<<endl;
}




    