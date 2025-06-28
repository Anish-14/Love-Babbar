#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<unordered_map> 
#include<list>
using namespace std;

// We used this MOD to prevent the int overflow for large values of nStairs
const int MOD = 1000000007;     // this was given in question 
int countDistinctWays(int nStairs) {
    if(nStairs <= 1 ){
        return 1;
    }

    int prev1 = 2;
    int prev2 = 1;

    for(int i = 3; i<=nStairs; i++){
        int curr = (prev1 + prev2)%MOD;
        // logic shift
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){
    int n;
    cin>>n;

    int ans = countDistinctWays(n);
    cout<<ans<<endl;
}


